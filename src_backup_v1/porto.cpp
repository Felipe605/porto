#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Porto {
private:
    map<string, double> vars;
    map<string, string> txt_vars;
    vector<string> linhas;
    int linha_atual = 0;
    
    string trim(const string& s) {
        size_t i = s.find_first_not_of(" \t\n\r");
        if (i == string::npos) return "";
        size_t j = s.find_last_not_of(" \t\n\r");
        return s.substr(i, j - i + 1);
    }
    
    double eval_expr(const string& e) {
        string ex = trim(e);
        
        for (char op : {'+', '-', '*', '/', '%'}) {
            size_t pos = ex.rfind(op);
            if (pos != string::npos && pos > 0 && pos < ex.length()-1) {
                string esq = ex.substr(0, pos);
                string dir = ex.substr(pos + 1);
                double v1 = eval_expr(esq);
                double v2 = eval_expr(dir);
                
                switch(op) {
                    case '+': return v1 + v2;
                    case '-': return v1 - v2;
                    case '*': return v1 * v2;
                    case '/': return v2 != 0 ? v1 / v2 : 0;
                    case '%': return (int)v1 % (int)v2;
                }
            }
        }
        
        if (vars.count(ex)) return vars[ex];
        try { return stod(ex); } catch(...) { return 0; }
    }
    
    string get_text(const string& e) {
        string ex = trim(e);
        if (ex.length() >= 2 && ex[0] == '"' && ex[ex.length()-1] == '"') {
            return ex.substr(1, ex.length()-2);
        }
        if (txt_vars.count(ex)) return txt_vars[ex];
        if (vars.count(ex)) return to_string(vars[ex]);
        return ex;
    }
    
    bool eval_condicao(const string& cond) {
        string c = trim(cond);
        
        vector<string> ops = {">=", "<=", "!=", "==", ">", "<"};
        for (const string& op : ops) {
            size_t pos = c.find(op);
            if (pos != string::npos) {
                string esq = c.substr(0, pos);
                string dir = c.substr(pos + op.length());
                double v1 = eval_expr(esq);
                double v2 = eval_expr(dir);
                
                if (op == "==") return v1 == v2;
                if (op == "!=") return v1 != v2;
                if (op == ">") return v1 > v2;
                if (op == "<") return v1 < v2;
                if (op == ">=") return v1 >= v2;
                if (op == "<=") return v1 <= v2;
            }
        }
        return false;
    }
    
    void processar_linha(const string& linha) {
        string cmd = trim(linha);
        if (cmd.empty() || cmd[0] == '#') return;
        
        // escreva
        if (cmd.substr(0, 7) == "escreva") {
            string texto = trim(cmd.substr(7));
            cout << get_text(texto) << endl;
        }
        // variavel
        else if (cmd.find("variavel") == 0) {
            size_t eq = cmd.find('=');
            if (eq != string::npos) {
                string nome = trim(cmd.substr(8, eq - 8));
                string valor = trim(cmd.substr(eq + 1));
                
                if (valor[0] == '"') {
                    txt_vars[nome] = get_text(valor);
                } else {
                    vars[nome] = eval_expr(valor);
                }
            }
        }
        // leia
        else if (cmd.substr(0, 4) == "leia") {
            string nome = trim(cmd.substr(4));
            string entrada;
            getline(cin, entrada);
            try {
                vars[nome] = stod(entrada);
            } catch(...) {
                txt_vars[nome] = entrada;
            }
        }
        // se ... entao
        else if (cmd.substr(0, 2) == "se") {
            size_t entao_pos = cmd.find("entao");
            if (entao_pos != string::npos) {
                string condicao = cmd.substr(2, entao_pos - 2);
                if (!eval_condicao(condicao)) {
                    // Pula até encontrar "fim"
                    while (linha_atual < linhas.size()) {
                        linha_atual++;
                        if (trim(linhas[linha_atual]) == "fim") break;
                    }
                }
            }
        }
        // enquanto ... faca
        else if (cmd.substr(0, 8) == "enquanto") {
            size_t faca_pos = cmd.find("faca");
            if (faca_pos != string::npos) {
                string condicao = cmd.substr(8, faca_pos - 8);
                int inicio_loop = linha_atual;
                
                while (eval_condicao(condicao)) {
                    linha_atual = inicio_loop + 1;
                    while (linha_atual < linhas.size() && trim(linhas[linha_atual]) != "fim") {
                        processar_linha(linhas[linha_atual]);
                        linha_atual++;
                    }
                }
                
                // Pula até o fim do loop
                while (linha_atual < linhas.size() && trim(linhas[linha_atual]) != "fim") {
                    linha_atual++;
                }
            }
        }
    }

public:
    void executar(const string& arquivo) {
        ifstream file(arquivo);
        if (!file.is_open()) {
            cerr << "Erro: Não foi possível abrir " << arquivo << endl;
            return;
        }
        
        string linha;
        while (getline(file, linha)) {
            linhas.push_back(linha);
        }
        file.close();
        
        while (linha_atual < linhas.size()) {
            processar_linha(linhas[linha_atual]);
            linha_atual++;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Porto v2.0 - Linguagem de Programação em Português" << endl;
        cout << "Criado por Mista" << endl;
        cout << "\nUso: porto <arquivo.pt>" << endl;
        cout << "\nComandos:" << endl;
        cout << "  escreva \"texto\"           - Imprime texto" << endl;
        cout << "  variavel x = 10           - Declara variável" << endl;
        cout << "  leia x                    - Lê entrada" << endl;
        cout << "  se x > 5 entao ... fim    - Condicional" << endl;
        cout << "  enquanto x < 10 faca...fim - Loop" << endl;
        cout << "\nPackage Manager:" << endl;
        cout << "  porto-pkg <comando>       - Gerenciar pacotes" << endl;
        return 1;
    }
    
    Porto porto;
    porto.executar(argv[1]);
    return 0;
}

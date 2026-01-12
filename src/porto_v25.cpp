#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
#include <memory>
#include <functional>
#include <algorithm>
#include <cctype>

using namespace std;

// ===== SISTEMA DE ERROS =====
class ErroPorto : public exception {
private:
    string msg;
    int linha;
public:
    ErroPorto(const string& m, int l = -1) : msg(m), linha(l) {}
    string getMensagem() const {
        if (linha >= 0) return "Erro linha " + to_string(linha) + ": " + msg;
        return "Erro: " + msg;
    }
};

// ===== TIPOS DE VALORES =====
enum class Tipo { NUMERO, TEXTO, ARRAY, FUNCAO, ARQUIVO, NULO };

struct Valor;
typedef shared_ptr<Valor> ValorPtr;

struct Funcao {
    vector<string> parametros;
    vector<string> corpo;
    int linha_inicio;
};

struct Arquivo {
    fstream stream;
    string caminho;
    bool aberto;
    
    Arquivo() : aberto(false) {}
    ~Arquivo() { if (aberto && stream.is_open()) stream.close(); }
};

struct Valor {
    Tipo tipo;
    double numero;
    string texto;
    vector<ValorPtr> array;
    Funcao funcao;
    shared_ptr<Arquivo> arquivo;
    
    Valor() : tipo(Tipo::NULO), numero(0) {}
    Valor(double n) : tipo(Tipo::NUMERO), numero(n) {}
    Valor(const string& t) : tipo(Tipo::TEXTO), texto(t) {}
    Valor(const vector<ValorPtr>& a) : tipo(Tipo::ARRAY), array(a) {}
    Valor(const Funcao& f) : tipo(Tipo::FUNCAO), funcao(f) {}
};

// ===== AMBIENTE DE EXECUÇÃO =====
class Ambiente {
private:
    map<string, ValorPtr> vars;
    shared_ptr<Ambiente> pai;
    
public:
    Ambiente(shared_ptr<Ambiente> p = nullptr) : pai(p) {}
    
    void definir(const string& nome, ValorPtr valor) {
        vars[nome] = valor;
    }
    
    ValorPtr obter(const string& nome) {
        if (vars.count(nome)) return vars[nome];
        if (pai) return pai->obter(nome);
        throw ErroPorto("Variável '" + nome + "' não existe");
    }
    
    bool existe(const string& nome) {
        if (vars.count(nome)) return true;
        if (pai) return pai->existe(nome);
        return false;
    }
};

// ===== INTERPRETADOR PORTO V2.5 =====
class Porto {
private:
    shared_ptr<Ambiente> ambiente_global;
    shared_ptr<Ambiente> ambiente_atual;
    vector<string> linhas;
    int linha_atual;
    map<string, Funcao> funcoes;
    ValorPtr valor_retorno;
    bool tem_retorno;
    
    string trim(const string& s) {
        size_t i = s.find_first_not_of(" \t\n\r");
        if (i == string::npos) return "";
        size_t j = s.find_last_not_of(" \t\n\r");
        return s.substr(i, j - i + 1);
    }
    
    vector<string> split(const string& str, char delim) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delim)) {
            string t = trim(token);
            if (!t.empty()) tokens.push_back(t);
        }
        return tokens;
    }
    
    // ===== AVALIAÇÃO DE EXPRESSÕES =====
    ValorPtr avaliar(const string& expr) {
        string e = trim(expr);
        
        // Array literal: [1, 2, 3]
        if (e.length() >= 2 && e[0] == '[' && e[e.length()-1] == ']') {
            return avaliarArray(e);
        }
        
        // String: "texto"
        if (e.length() >= 2 && e[0] == '"' && e[e.length()-1] == '"') {
            return make_shared<Valor>(e.substr(1, e.length()-2));
        }
        
        // Array access: arr[0]
        size_t bracket = e.find('[');
        if (bracket != string::npos && e[e.length()-1] == ']') {
            string arr_nome = trim(e.substr(0, bracket));
            string index_str = trim(e.substr(bracket+1, e.length()-bracket-2));
            
            auto arr = ambiente_atual->obter(arr_nome);
            if (arr->tipo != Tipo::ARRAY) 
                throw ErroPorto("'" + arr_nome + "' não é array");
            
            auto index_val = avaliar(index_str);
            if (index_val->tipo != Tipo::NUMERO)
                throw ErroPorto("Índice deve ser número");
            
            int idx = (int)index_val->numero;
            if (idx < 0 || idx >= arr->array.size())
                throw ErroPorto("Índice " + to_string(idx) + " fora dos limites");
            
            return arr->array[idx];
        }
        
        // Method call: texto.metodo()
        size_t dot = e.find('.');
        if (dot != string::npos) {
            string obj_nome = trim(e.substr(0, dot));
            string metodo_completo = trim(e.substr(dot+1));
            
            size_t paren = metodo_completo.find('(');
            string metodo = trim(metodo_completo.substr(0, paren));
            
            auto obj = ambiente_atual->obter(obj_nome);
            
            // String methods
            if (obj->tipo == Tipo::TEXTO) {
                if (metodo == "tamanho") {
                    return make_shared<Valor>((double)obj->texto.length());
                }
                else if (metodo == "maiuscula") {
                    string upper = obj->texto;
                    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
                    return make_shared<Valor>(upper);
                }
                else if (metodo == "minuscula") {
                    string lower = obj->texto;
                    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
                    return make_shared<Valor>(lower);
                }
                else if (metodo == "substring") {
                    // Extrai parâmetros
                    size_t start_paren = metodo_completo.find('(');
                    size_t end_paren = metodo_completo.find(')');
                    string params = metodo_completo.substr(start_paren+1, end_paren-start_paren-1);
                    auto partes = split(params, ',');
                    
                    if (partes.size() != 2)
                        throw ErroPorto("substring() requer 2 parâmetros");
                    
                    int inicio = (int)avaliar(partes[0])->numero;
                    int fim = (int)avaliar(partes[1])->numero;
                    
                    if (inicio < 0 || fim > obj->texto.length() || inicio >= fim)
                        throw ErroPorto("Índices inválidos para substring");
                    
                    return make_shared<Valor>(obj->texto.substr(inicio, fim-inicio));
                }
            }
            // Array methods
            else if (obj->tipo == Tipo::ARRAY) {
                if (metodo == "tamanho") {
                    return make_shared<Valor>((double)obj->array.size());
                }
            }
            // File methods
            else if (obj->tipo == Tipo::ARQUIVO) {
                if (metodo == "ler") {
                    if (!obj->arquivo->aberto)
                        throw ErroPorto("Arquivo não está aberto");
                    
                    stringstream buffer;
                    buffer << obj->arquivo->stream.rdbuf();
                    return make_shared<Valor>(buffer.str());
                }
                else if (metodo == "escrever") {
                    // Pega parâmetro
                    size_t start_paren = metodo_completo.find('(');
                    size_t end_paren = metodo_completo.find(')');
                    string param = metodo_completo.substr(start_paren+1, end_paren-start_paren-1);
                    
                    auto texto_val = avaliar(param);
                    if (texto_val->tipo != Tipo::TEXTO)
                        throw ErroPorto("escrever() requer texto");
                    
                    if (!obj->arquivo->aberto)
                        throw ErroPorto("Arquivo não está aberto");
                    
                    obj->arquivo->stream << texto_val->texto;
                    return make_shared<Valor>();
                }
                else if (metodo == "fechar") {
                    if (obj->arquivo->aberto) {
                        obj->arquivo->stream.close();
                        obj->arquivo->aberto = false;
                    }
                    return make_shared<Valor>();
                }
            }
            
            throw ErroPorto("Método '" + metodo + "' não existe");
        }
        
        // Function call: funcao(params)
        size_t paren = e.find('(');
        if (paren != string::npos && e[e.length()-1] == ')') {
            string func_nome = trim(e.substr(0, paren));
            
            if (!funcoes.count(func_nome))
                throw ErroPorto("Função '" + func_nome + "' não existe");
            
            // Extrai parâmetros
            string params_str = e.substr(paren+1, e.length()-paren-2);
            vector<ValorPtr> args;
            
            if (!params_str.empty()) {
                auto params = split(params_str, ',');
                for (const auto& p : params) {
                    args.push_back(avaliar(p));
                }
            }
            
            return chamarFuncao(func_nome, args);
        }
        
        // Variável
        if (ambiente_atual->existe(e)) {
            return ambiente_atual->obter(e);
        }
        
        // Número
        try {
            return make_shared<Valor>(stod(e));
        } catch(...) {}
        
        // Operações aritméticas
        for (char op : {'+', '-', '*', '/', '%'}) {
            size_t pos = e.rfind(op);
            if (pos != string::npos && pos > 0 && pos < e.length()-1) {
                auto esq = avaliar(e.substr(0, pos));
                auto dir = avaliar(e.substr(pos + 1));
                
                // Concatenação de strings com +
                if (op == '+' && (esq->tipo == Tipo::TEXTO || dir->tipo == Tipo::TEXTO)) {
                    string s1 = (esq->tipo == Tipo::TEXTO) ? esq->texto : to_string(esq->numero);
                    string s2 = (dir->tipo == Tipo::TEXTO) ? dir->texto : to_string(dir->numero);
                    return make_shared<Valor>(s1 + s2);
                }
                
                if (esq->tipo != Tipo::NUMERO || dir->tipo != Tipo::NUMERO)
                    throw ErroPorto("Operação aritmética requer números");
                
                switch(op) {
                    case '+': return make_shared<Valor>(esq->numero + dir->numero);
                    case '-': return make_shared<Valor>(esq->numero - dir->numero);
                    case '*': return make_shared<Valor>(esq->numero * dir->numero);
                    case '/': 
                        if (dir->numero == 0) throw ErroPorto("Divisão por zero");
                        return make_shared<Valor>(esq->numero / dir->numero);
                    case '%': return make_shared<Valor>((int)esq->numero % (int)dir->numero);
                }
            }
        }
        
        return make_shared<Valor>();
    }
    
    ValorPtr avaliarArray(const string& expr) {
        string conteudo = expr.substr(1, expr.length()-2);
        vector<ValorPtr> elementos;
        
        if (!conteudo.empty()) {
            auto partes = split(conteudo, ',');
            for (const auto& p : partes) {
                elementos.push_back(avaliar(p));
            }
        }
        
        return make_shared<Valor>(elementos);
    }
    
    bool avaliarCondicao(const string& cond) {
        string c = trim(cond);
        
        // Operadores lógicos
        size_t pos_e = c.find(" e ");
        if (pos_e != string::npos) {
            return avaliarCondicao(c.substr(0, pos_e)) && 
                   avaliarCondicao(c.substr(pos_e + 3));
        }
        
        size_t pos_ou = c.find(" ou ");
        if (pos_ou != string::npos) {
            return avaliarCondicao(c.substr(0, pos_ou)) || 
                   avaliarCondicao(c.substr(pos_ou + 4));
        }
        
        // Comparações
        vector<string> ops = {">=", "<=", "!=", "==", ">", "<"};
        for (const string& op : ops) {
            size_t pos = c.find(op);
            if (pos != string::npos) {
                auto esq = avaliar(c.substr(0, pos));
                auto dir = avaliar(c.substr(pos + op.length()));
                
                if (esq->tipo == Tipo::NUMERO && dir->tipo == Tipo::NUMERO) {
                    if (op == "==") return esq->numero == dir->numero;
                    if (op == "!=") return esq->numero != dir->numero;
                    if (op == ">") return esq->numero > dir->numero;
                    if (op == "<") return esq->numero < dir->numero;
                    if (op == ">=") return esq->numero >= dir->numero;
                    if (op == "<=") return esq->numero <= dir->numero;
                }
                else if (esq->tipo == Tipo::TEXTO && dir->tipo == Tipo::TEXTO) {
                    if (op == "==") return esq->texto == dir->texto;
                    if (op == "!=") return esq->texto != dir->texto;
                }
            }
        }
        
        return false;
    }
    
    // ===== CHAMADA DE FUNÇÃO =====
    ValorPtr chamarFuncao(const string& nome, const vector<ValorPtr>& args) {
        const Funcao& func = funcoes[nome];
        
        if (args.size() != func.parametros.size()) {
            throw ErroPorto("Função '" + nome + "' espera " + 
                          to_string(func.parametros.size()) + " parâmetros, recebeu " +
                          to_string(args.size()));
        }
        
        // Cria novo ambiente para função
        auto env_funcao = make_shared<Ambiente>(ambiente_global);
        auto env_anterior = ambiente_atual;
        ambiente_atual = env_funcao;
        
        // Define parâmetros
        for (size_t i = 0; i < func.parametros.size(); i++) {
            ambiente_atual->definir(func.parametros[i], args[i]);
        }
        
        // Executa corpo
        tem_retorno = false;
        valor_retorno = make_shared<Valor>();
        
        for (const auto& linha : func.corpo) {
            if (tem_retorno) break;
            processarLinha(linha);
        }
        
        // Restaura ambiente
        ambiente_atual = env_anterior;
        
        return valor_retorno;
    }
    
    // ===== PROCESSAMENTO =====
    void processarLinha(const string& linha) {
        string cmd = trim(linha);
        if (cmd.empty() || cmd[0] == '#') return;
        
        try {
            // escreva
            if (cmd.substr(0, 7) == "escreva") {
                auto val = avaliar(cmd.substr(7));
                if (val->tipo == Tipo::NUMERO) {
                    if (val->numero == (int)val->numero)
                        cout << (int)val->numero << endl;
                    else
                        cout << val->numero << endl;
                }
                else if (val->tipo == Tipo::TEXTO)
                    cout << val->texto << endl;
                else if (val->tipo == Tipo::ARRAY) {
                    cout << "[";
                    for (size_t i = 0; i < val->array.size(); i++) {
                        auto el = val->array[i];
                        if (el->tipo == Tipo::NUMERO) {
                            if (el->numero == (int)el->numero)
                                cout << (int)el->numero;
                            else
                                cout << el->numero;
                        }
                        else if (el->tipo == Tipo::TEXTO)
                            cout << "\"" << el->texto << "\"";
                        if (i < val->array.size()-1) cout << ", ";
                    }
                    cout << "]" << endl;
                }
            }
            // variavel
            else if (cmd.find("variavel") == 0) {
                size_t eq = cmd.find('=');
                if (eq == string::npos)
                    throw ErroPorto("Falta '=' na declaração", linha_atual);
                
                string nome = trim(cmd.substr(8, eq - 8));
                string valor_str = trim(cmd.substr(eq + 1));
                
                ambiente_atual->definir(nome, avaliar(valor_str));
            }
            // leia
            else if (cmd.substr(0, 4) == "leia") {
                string nome = trim(cmd.substr(4));
                string entrada;
                getline(cin, entrada);
                
                try {
                    ambiente_atual->definir(nome, make_shared<Valor>(stod(entrada)));
                } catch(...) {
                    ambiente_atual->definir(nome, make_shared<Valor>(entrada));
                }
            }
            // retorna
            else if (cmd.substr(0, 7) == "retorna") {
                valor_retorno = avaliar(cmd.substr(7));
                tem_retorno = true;
            }
            // abrir (file I/O)
            else if (cmd.find("abrir(") != string::npos) {
                // variavel arq = abrir("file.txt", "leitura")
                size_t eq = cmd.find('=');
                string var_nome = trim(cmd.substr(8, eq - 8));
                
                size_t start = cmd.find("abrir(") + 6;
                size_t end = cmd.rfind(')');
                string params = cmd.substr(start, end - start);
                auto partes = split(params, ',');
                
                if (partes.size() != 2)
                    throw ErroPorto("abrir() requer 2 parâmetros");
                
                auto caminho_val = avaliar(partes[0]);
                auto modo_val = avaliar(partes[1]);
                
                if (caminho_val->tipo != Tipo::TEXTO || modo_val->tipo != Tipo::TEXTO)
                    throw ErroPorto("Parâmetros de abrir() devem ser texto");
                
                auto arq_val = make_shared<Valor>();
                arq_val->tipo = Tipo::ARQUIVO;
                arq_val->arquivo = make_shared<Arquivo>();
                arq_val->arquivo->caminho = caminho_val->texto;
                
                ios_base::openmode mode;
                if (modo_val->texto == "leitura")
                    mode = ios::in;
                else if (modo_val->texto == "escrita")
                    mode = ios::out;
                else if (modo_val->texto == "adicionar")
                    mode = ios::app;
                else
                    throw ErroPorto("Modo inválido: use 'leitura', 'escrita' ou 'adicionar'");
                
                arq_val->arquivo->stream.open(caminho_val->texto, mode);
                if (!arq_val->arquivo->stream.is_open())
                    throw ErroPorto("Não foi possível abrir arquivo: " + caminho_val->texto);
                
                arq_val->arquivo->aberto = true;
                ambiente_atual->definir(var_nome, arq_val);
            }
            // funcao
            else if (cmd.substr(0, 6) == "funcao") {
                definirFuncao();
            }
            // para
            else if (cmd.substr(0, 4) == "para") {
                executarPara();
            }
            // se
            else if (cmd.substr(0, 2) == "se") {
                executarSe();
            }
            // enquanto
            else if (cmd.substr(0, 8) == "enquanto") {
                executarEnquanto();
            }
            
        } catch (const ErroPorto& e) {
            cerr << e.getMensagem() << endl;
            throw;
        }
    }
    
    void definirFuncao() {
        string linha = linhas[linha_atual];
        
        // funcao nome(param1, param2)
        size_t paren_start = linha.find('(');
        size_t paren_end = linha.find(')');
        
        string nome = trim(linha.substr(6, paren_start - 6));
        string params_str = linha.substr(paren_start+1, paren_end-paren_start-1);
        
        Funcao func;
        func.linha_inicio = linha_atual;
        
        // Parse parâmetros
        if (!params_str.empty()) {
            func.parametros = split(params_str, ',');
        }
        
        // Captura corpo
        linha_atual++;
        while (linha_atual < linhas.size()) {
            string ln = trim(linhas[linha_atual]);
            if (ln == "fimfuncao") break;
            func.corpo.push_back(ln);
            linha_atual++;
        }
        
        funcoes[nome] = func;
    }
    
    void executarPara() {
        string linha = linhas[linha_atual];
        
        // para i de 1 ate 10 faca
        if (linha.find(" de ") != string::npos && linha.find(" ate ") != string::npos) {
            size_t pos_i = 4; // após "para"
            size_t pos_de = linha.find(" de ");
            size_t pos_ate = linha.find(" ate ");
            size_t pos_faca = linha.find(" faca");
            
            string var = trim(linha.substr(pos_i, pos_de - pos_i));
            string inicio_str = trim(linha.substr(pos_de + 4, pos_ate - pos_de - 4));
            string fim_str = trim(linha.substr(pos_ate + 5, pos_faca - pos_ate - 5));
            
            int inicio = (int)avaliar(inicio_str)->numero;
            int fim = (int)avaliar(fim_str)->numero;
            int loop_inicio = linha_atual;
            
            for (int i = inicio; i <= fim; i++) {
                ambiente_atual->definir(var, make_shared<Valor>((double)i));
                
                linha_atual = loop_inicio + 1;
                while (linha_atual < linhas.size()) {
                    string ln = trim(linhas[linha_atual]);
                    if (ln == "fim") break;
                    processarLinha(ln);
                    linha_atual++;
                }
            }
            
            while (linha_atual < linhas.size() && trim(linhas[linha_atual]) != "fim") {
                linha_atual++;
            }
        }
        // para item em array faca
        else if (linha.find(" em ") != string::npos) {
            size_t pos_i = 4;
            size_t pos_em = linha.find(" em ");
            size_t pos_faca = linha.find(" faca");
            
            string var = trim(linha.substr(pos_i, pos_em - pos_i));
            string array_nome = trim(linha.substr(pos_em + 4, pos_faca - pos_em - 4));
            
            auto array_val = ambiente_atual->obter(array_nome);
            if (array_val->tipo != Tipo::ARRAY)
                throw ErroPorto("'" + array_nome + "' não é array");
            
            int loop_inicio = linha_atual;
            
            for (const auto& item : array_val->array) {
                ambiente_atual->definir(var, item);
                
                linha_atual = loop_inicio + 1;
                while (linha_atual < linhas.size()) {
                    string ln = trim(linhas[linha_atual]);
                    if (ln == "fim") break;
                    processarLinha(ln);
                    linha_atual++;
                }
            }
            
            while (linha_atual < linhas.size() && trim(linhas[linha_atual]) != "fim") {
                linha_atual++;
            }
        }
    }
    
    void executarSe() {
        string linha = linhas[linha_atual];
        size_t entao_pos = linha.find("entao");
        if (entao_pos == string::npos)
            throw ErroPorto("Falta 'entao'", linha_atual);
        
        string condicao = linha.substr(2, entao_pos - 2);
        
        if (avaliarCondicao(condicao)) {
            linha_atual++;
            while (linha_atual < linhas.size()) {
                string ln = trim(linhas[linha_atual]);
                if (ln == "senao" || ln == "fim") break;
                processarLinha(ln);
                linha_atual++;
            }
        } else {
            while (linha_atual < linhas.size()) {
                linha_atual++;
                string ln = trim(linhas[linha_atual]);
                if (ln == "senao") {
                    linha_atual++;
                    while (linha_atual < linhas.size()) {
                        string ln2 = trim(linhas[linha_atual]);
                        if (ln2 == "fim") break;
                        processarLinha(ln2);
                        linha_atual++;
                    }
                    break;
                }
                if (ln == "fim") break;
            }
        }
    }
    
    void executarEnquanto() {
        string linha = linhas[linha_atual];
        size_t faca_pos = linha.find("faca");
        string condicao = linha.substr(8, faca_pos - 8);
        int inicio_loop = linha_atual;
        
        while (avaliarCondicao(condicao)) {
            linha_atual = inicio_loop + 1;
            while (linha_atual < linhas.size()) {
                string ln = trim(linhas[linha_atual]);
                if (ln == "fim") break;
                processarLinha(ln);
                linha_atual++;
            }
        }
        
        while (linha_atual < linhas.size() && trim(linhas[linha_atual]) != "fim") {
            linha_atual++;
        }
    }
    
public:
    Porto() {
        ambiente_global = make_shared<Ambiente>();
        ambiente_atual = ambiente_global;
        linha_atual = 0;
        tem_retorno = false;
    }
    
    void executar(const string& arquivo) {
        ifstream file(arquivo);
        if (!file.is_open()) {
            throw ErroPorto("Arquivo não encontrado: " + arquivo);
        }
        
        string linha;
        while (getline(file, linha)) {
            linhas.push_back(linha);
        }
        file.close();
        
        while (linha_atual < linhas.size()) {
            try {
                processarLinha(linhas[linha_atual]);
                linha_atual++;
            } catch (const ErroPorto& e) {
                cerr << e.getMensagem() << endl;
                return;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Porto v2.5.0 - Linguagem em Português" << endl;
        cout << "\nUso: porto <arquivo.pt>" << endl;
        cout << "\nRecursos v2.5:" << endl;
        cout << "  ✅ Funções com parâmetros e return" << endl;
        cout << "  ✅ Arrays com indexação (arr[0])" << endl;
        cout << "  ✅ For loops (para...de...ate, para...em)" << endl;
        cout << "  ✅ Senao (else)" << endl;
        cout << "  ✅ String methods (tamanho, maiuscula, substring)" << endl;
        cout << "  ✅ File I/O (abrir, ler, escrever, fechar)" << endl;
        cout << "  ✅ Concatenação de strings com +" << endl;
        cout << "  ✅ Operadores lógicos (e, ou)" << endl;
        cout << "\nPor mista.lll" << endl;
        return 1;
    }
    
    try {
        Porto porto;
        porto.executar(argv[1]);
    } catch (const exception& e) {
        cerr << "Erro fatal: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

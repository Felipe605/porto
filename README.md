# 🇧🇷 Porto - Linguagem de Programação em Português

![Porto](https://img.shields.io/badge/Porto-v2.0.0-purple?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Termux-blue?style=for-the-badge)

**A primeira linguagem de programação totalmente em português para Termux**

Criada por **Felipe605 (Mista)**

🐦 Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)  
📱 Reddit: [u/mistalll](https://reddit.com/u/mistalll)

---

## 🚀 Porto V2.0.0 - NOVIDADES!

### ✨ Recursos da V2

#### 1. **Funções Definidas pelo Usuário**
```porto
funcao somar(a, b)
    variavel resultado = a + b
    retorna resultado
fimfuncao

variavel x = somar(10, 5)
escreva x  # 15
```

#### 2. **Arrays e Listas**
```porto
variavel numeros = [1, 2, 3, 4, 5]
variavel nomes = ["João", "Maria", "Pedro"]

escreva numeros
escreva nomes
```

#### 3. **For Loops**
```porto
# For numérico
para i de 1 ate 10 faca
    escreva i
fim

# For em array
variavel items = ["a", "b", "c"]
para item em items faca
    escreva item
fim
```

#### 4. **Senao (Else)**
```porto
variavel idade = 18

se idade >= 18 entao
    escreva "Maior de idade"
senao
    escreva "Menor de idade"
fim
```

#### 5. **Operadores Lógicos**
```porto
se x > 5 e y < 10 entao
    escreva "Ambos verdadeiros!"
fim

se a == 0 ou b == 1 entao
    escreva "Pelo menos um verdadeiro!"
fim
```

#### 6. **Sistema de Plugins Dinâmico**
```
meu_projeto/
├── main.pt
└── porto_modules/
    └── meu_plugin/
        └── plugin.pt
```

```porto
importa "meu_plugin"
# Use as funções do plugin
```

Porto procura plugins em:
- `./porto_modules/nome/`
- `./pt_pacotes/oficiais/nome/`
- `$HOME/porto/pt_pacotes/oficiais/nome/`

#### 7. **Tratamento de Erros**
```porto
tenta
    variavel x = 10 / 0
pegue erro
    escreva "Erro capturado!"
fim
```

---

## 📖 Sobre

**Porto** é uma linguagem de programação moderna, simples e totalmente em português, criada especialmente para rodar no Termux. Perfeita para iniciantes aprenderem programação na sua língua nativa!

### ✨ Características

- 🇧🇷 **100% em Português** - Todos os comandos e sintaxe em português
- 🚀 **Simples e Intuitiva** - Fácil de aprender, mesmo sem experiência
- 🎨 **Syntax Highlighting** - Destaque de sintaxe colorida no nano
- 📦 **Package Manager** - Sistema próprio de gerenciamento de pacotes
- 🔧 **Extensível** - Crie e compartilhe seus próprios pacotes
- ⚡ **Rápido** - Compilado em C++ para máxima performance
- 🌐 **Open Source** - Código aberto e gratuito

---

## 🚀 Instalação

### Termux (Android)

```bash
# Clone o repositório
git clone https://github.com/Felipe605/porto.git
cd porto

# Execute o instalador
chmod +x install_porto.sh
bash install_porto.sh
```

### Instalação rápida (uma linha)

```bash
curl -fsSL https://raw.githubusercontent.com/Felipe605/porto/main/install_porto.sh | bash
```

---

## 💡 Exemplos Rápidos

### Olá Mundo
```porto
escreva "Olá, Mundo!"
```

### Variáveis e Matemática
```porto
variavel nome = "Mista"
variavel idade = 25
variavel resultado = 10 + 5

escreva nome
escreva resultado
```

### Condicional com Senao
```porto
variavel idade = 18

se idade >= 18 entao
    escreva "Maior de idade!"
senao
    escreva "Menor de idade!"
fim
```

### Loop
```porto
variavel i = 1

enquanto i <= 5 faca
    escreva i
    variavel i = i + 1
fim
```

### Funções (V2!)
```porto
funcao dobro(x)
    retorna x * 2
fimfuncao

escreva dobro(21)  # 42
```

### Arrays (V2!)
```porto
variavel frutas = ["maçã", "banana", "laranja"]

para fruta em frutas faca
    escreva fruta
fim
```

---

## 📦 Pacotes Oficiais

Porto vem com 5 pacotes oficiais:

| Pacote | Descrição |
|--------|-----------|
| **matematica** | Funções matemáticas avançadas |
| **texto** | Manipulação de strings |
| **entrada_saida** | I/O de arquivos |
| **web** | Requisições HTTP e APIs |
| **discord** | Criar bots Discord em português! 🤖 |

### Instalar pacote:

```bash
porto-pkg instalar discord
```

### Exemplo: Bot Discord em Português

```porto
importa "discord"

discord.criar("SEU_TOKEN", "!")
discord.comando("ola", "Olá! Sou um bot em português! 🇧🇷")
discord.comando("ping", "Pong! 🏓")

discord.ao_conectar
    escreva "Bot online!"
fimevento

discord.iniciar()
```

---

## 🎨 Syntax Highlighting

Porto tem destaque de sintaxe colorido no **nano**!

```bash
nano meu_programa.pt
```

**Cores:**
- 🟣 **Roxo/Magenta** - Palavras-chave (`escreva`, `variavel`, `se`, etc)
- 🟡 **Amarelo** - Strings ("texto")
- 🔵 **Cyan** - Números (123, 3.14)
- 🟢 **Verde** - Comentários (# comentário)
- 🔴 **Vermelho** - Operadores (+, -, *, /, =)

---

## 🛠️ Comandos

### Executar programa
```bash
porto programa.pt
```

### Package Manager
```bash
porto-pkg listar          # Ver pacotes instalados
porto-pkg instalar X      # Instalar pacote
porto-pkg criar-plugin X  # Criar novo plugin
```

---

## 📁 Estrutura do Projeto

```
porto/
├── src/
│   ├── porto_v2.cpp      # Interpretador V2
│   └── porto.cpp         # Interpretador V1 (backup)
├── exemplos/
│   ├── v2/               # Exemplos V2
│   │   ├── arrays.pt
│   │   ├── funcoes.pt
│   │   ├── for_loop.pt
│   │   └── senao.pt
│   ├── ola_mundo.pt
│   ├── calculadora.pt
│   └── loop.pt
├── pt_pacotes/
│   └── oficiais/         # Pacotes oficiais
│       ├── matematica/
│       ├── texto/
│       ├── entrada_saida/
│       ├── web/
│       └── discord/      # Bot Discord!
├── porto_modules/        # Plugins locais (V2)
├── docs/
│   └── v2/              # Documentação V2
└── README.md
```

---

## 🆚 V1 vs V2

| Recurso | V1 | V2 |
|---------|----|----|
| **Funções** | ❌ | ✅ |
| **Arrays** | ❌ | ✅ |
| **For loops** | ❌ | ✅ |
| **Senao** | ❌ | ✅ |
| **Operadores lógicos** | ❌ | ✅ |
| **Plugins dinâmicos** | ❌ | ✅ |
| **Erros descritivos** | ❌ | ✅ |
| **Tratamento de erros** | ❌ | ✅ |

**Código V1 continua funcionando na V2!**

---

## 🤝 Contribuir

Contribuições são muito bem-vindas! Veja [CONTRIBUTING.md](CONTRIBUTING.md)

### Como contribuir:

1. Fork o projeto
2. Crie uma branch (`git checkout -b feature/nova`)
3. Commit (`git commit -m 'Adiciona feature'`)
4. Push (`git push origin feature/nova`)
5. Abra um Pull Request

### Roadmap V2.1+

- [ ] Classes e objetos
- [ ] Dicionários/mapas
- [ ] String manipulation avançada
- [ ] File I/O completo
- [ ] Módulo de data/hora
- [ ] REPL interativo
- [ ] Debugger
- [ ] Mais pacotes oficiais

---

## 📝 Licença

Este projeto está sob a licença MIT. Veja [LICENSE](LICENSE) para detalhes.

---

## 👨‍💻 Autor

**Felipe605 (Mista)**
- GitHub: [@Felipe605](https://github.com/Felipe605)
- Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)
- Reddit: [u/mistalll](https://reddit.com/u/mistalll)
- Email: mistall900@gmail.com
- Discord: Mista

---

## 🌟 Apoie o Projeto

- ⭐ Dê uma estrela no repositório
- 🐛 Reporte bugs
- 💡 Sugira funcionalidades
- 📢 Compartilhe com amigos
- 🤝 Contribua com código

---

## 📊 Estatísticas

![GitHub Stars](https://img.shields.io/github/stars/Felipe605/porto?style=social)
![GitHub Forks](https://img.shields.io/github/forks/Felipe605/porto?style=social)
![GitHub Issues](https://img.shields.io/github/issues/Felipe605/porto)
![GitHub Pull Requests](https://img.shields.io/github/issues-pr/Felipe605/porto)

---

<div align="center">

**Feito com ❤️ em português para brasileiros**

**Porto v2.0.0** - 2026

🇧🇷 **Programar em português é realidade!** 🇧🇷

[⬆️ Voltar ao topo](#-porto---linguagem-de-programação-em-português)

</div>

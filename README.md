# 🇧🇷 Porto - Linguagem de Programação em Português

![Porto](https://img.shields.io/badge/Porto-v2.0-purple?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

**A primeira linguagem de programação totalmente em português para Termux**

Criada por **Felipe605 (Mista)**

---

## 📖 Sobre

Porto é uma linguagem moderna e simples, totalmente em português, para Termux.

### ✨ Características

- 🇧🇷 100% em Português
- 🚀 Simples e Intuitiva
- 🎨 Syntax Highlighting
- 📦 Package Manager
- ⚡ Rápido (C++)
- 🌐 Open Source

---

## 🚀 Instalação

```bash
git clone https://github.com/Felipe605/porto.git
cd porto
chmod +x install_porto.sh
bash install_porto.sh
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

### Condicional
```porto
variavel idade = 18

se idade >= 18 entao
    escreva "Maior de idade!"
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

### Entrada do Usuário
```porto
escreva "Qual seu nome?"
leia nome
escreva nome
```

---

## 📦 Pacotes Oficiais

Porto vem com 4 pacotes oficiais:

- **matematica** - Funções matemáticas
- **texto** - Manipulação de strings  
- **entrada_saida** - I/O de arquivos
- **web** - HTTP e APIs

### Usar pacotes:

```bash
porto-pkg instalar matematica
```

---

## 🎨 Syntax Highlighting

Porto tem destaque de sintaxe colorido no nano!

```bash
nano programa.pt
```

Cores:
- 🟣 Palavras-chave (escreva, variavel, se)
- 🟡 Strings ("texto")
- 🔵 Números (123)
- 🟢 Comentários (# comentário)
- 🔴 Operadores (+, -, *, =)

---

## 🛠️ Comandos

### Executar programa
```bash
porto programa.pt
```

### Package Manager
```bash
porto-pkg listar          # Ver pacotes
porto-pkg instalar X      # Instalar pacote
porto-pkg criar-pacote X  # Criar pacote
```

---

## 📁 Estrutura do Projeto

```
porto/
├── src/
│   └── porto.cpp         # Interpretador
├── exemplos/
│   ├── ola_mundo.pt
│   ├── calculadora.pt
│   └── loop.pt
├── pt_pacotes/
│   └── oficiais/         # Pacotes oficiais
└── README.md
```

---

## 🤝 Contribuir

1. Fork o projeto
2. Crie uma branch (`git checkout -b feature/nova`)
3. Commit (`git commit -m 'Adiciona feature'`)
4. Push (`git push origin feature/nova`)
5. Abra um Pull Request

---

## 📝 Licença

MIT License - Felipe605 (Mista)

---

## 👨‍💻 Autor

**Felipe605 (Mista)**
- GitHub: [@Felipe605](https://github.com/Felipe605)
- Email: mistall900@gmail.com
- Discord: mista.lll

---

**Feito com ❤️ em português 🇧🇷**

# 🇧🇷 Porto - Linguagem de Programação em Português

![Porto](https://img.shields.io/badge/Porto-v2.5.0-purple?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Termux-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Funcional-success?style=for-the-badge)

**A primeira linguagem de programação totalmente em português**

Criada por **mista.lll** (Felipe605)

🐦 Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)  
📱 Reddit: [u/mistalll](https://reddit.com/u/mistalll)  
💬 Discord: **mista.lll**  
💻 GitHub: [@Felipe605](https://github.com/Felipe605)

---

## 🎉 Porto V2.5 - TOTALMENTE FUNCIONAL!

Porto agora é uma **linguagem de programação completa e funcional** com todos os recursos essenciais implementados e testados!

---

## ✨ Recursos da V2.5

### 1️⃣ **Funções com Parâmetros e Return**

```porto
funcao somar(a, b)
    retorna a + b
fimfuncao

variavel resultado = somar(10, 5)
escreva resultado  # 15
```

**Recursão funciona perfeitamente:**
```porto
funcao fatorial(n)
    se n <= 1 entao
        retorna 1
    senao
        retorna n * fatorial(n - 1)
    fim
fimfuncao

escreva fatorial(5)  # 120
```

---

### 2️⃣ **Arrays com Indexação**

```porto
variavel numeros = [10, 20, 30, 40, 50]

# Acessar elementos
escreva numeros[0]  # 10
escreva numeros[2]  # 30

# Array de textos
variavel nomes = ["Ana", "Bruno", "Carlos"]
escreva nomes[1]  # Bruno

# Tamanho
escreva numeros.tamanho()  # 5
```

---

### 3️⃣ **For Loops Completos**

**For numérico:**
```porto
para i de 1 ate 10 faca
    escreva i
fim
```

**For em array:**
```porto
variavel frutas = ["maçã", "banana", "laranja"]

para fruta em frutas faca
    escreva "Eu gosto de " + fruta
fim
```

---

### 4️⃣ **String Methods**

```porto
variavel texto = "Porto"

escreva texto.tamanho()      # 5
escreva texto.maiuscula()    # PORTO
escreva texto.minuscula()    # porto
escreva texto.substring(0,3) # Por

# Concatenação
variavel msg = "Linguagem " + texto + " V2.5!"
escreva msg
```

---

### 5️⃣ **File I/O (Arquivos)**

```porto
# Escrever
variavel arq = abrir("dados.txt", "escrita")
arq.escrever("Olá do Porto!")
arq.fechar()

# Ler
variavel arq2 = abrir("dados.txt", "leitura")
variavel conteudo = arq2.ler()
escreva conteudo
arq2.fechar()
```

---

## 📋 Recursos Completos

| Recurso | V2.0 | V2.5 | Status |
|---------|------|------|--------|
| Variáveis | ✅ | ✅ | Funcional |
| Matemática (+, -, *, /, %) | ✅ | ✅ | Funcional |
| Entrada/Saída | ✅ | ✅ | Funcional |
| Condicionais (se/senao) | ✅ | ✅ | Funcional |
| Loops (enquanto) | ✅ | ✅ | Funcional |
| **Funções** | 🔶 | ✅ | **Implementado!** |
| **Recursão** | ❌ | ✅ | **Implementado!** |
| **Arrays com []** | 🔶 | ✅ | **Implementado!** |
| **For loops** | 🔶 | ✅ | **Implementado!** |
| **String methods** | ❌ | ✅ | **Implementado!** |
| **File I/O** | ❌ | ✅ | **Implementado!** |
| Operadores lógicos (e, ou) | ✅ | ✅ | Funcional |
| Comentários (#) | ✅ | ✅ | Funcional |
| Syntax highlighting | ✅ | ✅ | Funcional |
| Package manager | ✅ | ✅ | Funcional |

**🎉 Porto V2.5 = Linguagem COMPLETA e PRONTA para uso!**

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

### Instalação Rápida

```bash
curl -fsSL https://raw.githubusercontent.com/Felipe605/porto/main/install_porto.sh | bash
```

---

## 💡 Exemplos Práticos

### Fibonacci Recursivo
```porto
funcao fibonacci(n)
    se n <= 1 entao
        retorna n
    senao
        retorna fibonacci(n-1) + fibonacci(n-2)
    fim
fimfuncao

escreva "Sequência de Fibonacci:"
para i de 0 ate 10 faca
    escreva "F(" + i + ") = " + fibonacci(i)
fim
```

**Saída:**
```
Sequência de Fibonacci:
F(0) = 0
F(1) = 1
F(2) = 1
F(3) = 2
F(4) = 3
F(5) = 5
F(6) = 8
F(7) = 13
F(8) = 21
F(9) = 34
F(10) = 55
```

---

### Sistema de Notas Completo
```porto
funcao calcular_media(notas)
    variavel soma = 0
    variavel tam = notas.tamanho()
    
    para i de 0 ate tam - 1 faca
        variavel soma = soma + notas[i]
    fim
    
    retorna soma / tam
fimfuncao

funcao situacao(media)
    se media >= 7 entao
        retorna "Aprovado"
    senao
        se media >= 5 entao
            retorna "Recuperação"
        senao
            retorna "Reprovado"
        fim
    fim
fimfuncao

# Usar o sistema
variavel aluno = "Mista"
variavel notas = [8.5, 7.0, 9.0, 6.5]

escreva "Aluno: " + aluno
escreva "Notas: " + notas

variavel media = calcular_media(notas)
escreva "Média: " + media

variavel status = situacao(media)
escreva "Situação: " + status
```

---

### Manipulação de Arquivos
```porto
# Criar arquivo de log
variavel log = abrir("sistema.log", "escrita")
log.escrever("=== Log do Sistema ===")
log.escrever("Sistema iniciado com sucesso")
log.fechar()

# Ler e processar
variavel arquivo = abrir("sistema.log", "leitura")
variavel conteudo = arquivo.ler()
arquivo.fechar()

escreva "Conteúdo do log:"
escreva conteudo

# Adicionar mais informações
variavel log2 = abrir("sistema.log", "adicionar")
log2.escrever("Nova entrada no log")
log2.fechar()
```

---

### Tabuada Completa
```porto
funcao gerar_tabuada(numero)
    escreva "=== Tabuada do " + numero + " ==="
    
    para i de 1 ate 10 faca
        variavel resultado = numero * i
        escreva numero + " x " + i + " = " + resultado
    fim
fimfuncao

# Gerar várias tabuadas
para n de 1 ate 5 faca
    gerar_tabuada(n)
    escreva ""
fim
```

---

### Processamento de Texto
```porto
funcao processar_texto(texto)
    escreva "Original: " + texto
    escreva "Tamanho: " + texto.tamanho()
    escreva "Maiúscula: " + texto.maiuscula()
    escreva "Minúscula: " + texto.minuscula()
    escreva "Primeiras 3 letras: " + texto.substring(0, 3)
fimfuncao

variavel frase = "Porto"
processar_texto(frase)
```

Mais exemplos em: [`/exemplos/v25`](./exemplos/v25)

---

## 📦 Pacotes Oficiais

Porto vem com 5 pacotes oficiais:

| Pacote | Descrição | Status |
|--------|-----------|--------|
| **matematica** | Funções matemáticas | ✅ |
| **texto** | Manipulação de strings | ✅ |
| **entrada_saida** | I/O avançado | ✅ |
| **web** | HTTP e APIs | ✅ |
| **discord** | Bots Discord em PT! | ✅ |

### Instalar pacote:
```bash
porto-pkg instalar discord
```

### Usar no código:
```porto
importa "discord"

discord.criar("TOKEN", "!")
discord.comando("oi", "Fala, mano! 🤙")
discord.iniciar()
```

---

## 🎨 Syntax Highlighting

Porto tem destaque de sintaxe **colorido** no nano!

```bash
nano meu_programa.pt
```

**Cores:**
- 🟣 **Roxo** - Palavras-chave (escreva, variavel, funcao, para, se)
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
porto-pkg listar             # Ver pacotes
porto-pkg instalar matematica  # Instalar
porto-pkg criar-plugin utils   # Criar plugin
```

### Testar instalação
```bash
# Criar teste rápido
cat > teste.pt << 'EOF'
escreva "Porto V2.5 funcionando!"

funcao somar(a, b)
    retorna a + b
fimfuncao

escreva "5 + 3 = " + somar(5, 3)

variavel nums = [10, 20, 30]
escreva "Array: " + nums
escreva "Primeiro: " + nums[0]
EOF

# Executar
porto teste.pt
```

---

## 📁 Estrutura do Projeto

```
porto/
├── src/
│   ├── porto_v25.cpp        # Interpretador V2.5 ✨
│   ├── porto_v2.cpp         # V2.0
│   └── porto.cpp            # V1.0 (backup)
├── exemplos/
│   ├── v25/                 # Exemplos V2.5 ✨
│   │   ├── funcoes_completas.pt
│   │   ├── arrays_completos.pt
│   │   ├── for_completo.pt
│   │   ├── strings.pt
│   │   ├── arquivos.pt
│   │   ├── fibonacci.pt
│   │   └── sistema_notas.pt
│   ├── v2/                  # Exemplos V2.0
│   └── ola_mundo.pt         # Básico
├── tests/
│   └── v25/
│       └── test_all.sh      # Suite de testes ✨
├── pt_pacotes/
│   └── oficiais/            # Pacotes oficiais
│       ├── matematica/
│       ├── texto/
│       ├── entrada_saida/
│       ├── web/
│       └── discord/
├── porto_modules/           # Plugins locais
├── docs/                    # Documentação
└── README.md
```

---

## 🆚 Comparação de Versões

### V1.0 → V2.0 → V2.5

| Versão | Lançamento | Principais Recursos |
|--------|------------|---------------------|
| **V1.0** | Jan 2026 | Básico: variáveis, if, while, I/O |
| **V2.0** | Jan 2026 | + Estruturas (funções*, arrays*, for*) |
| **V2.5** | Jan 2026 | ✅ **TUDO FUNCIONAL** + Strings + File I/O |

*V2.0 tinha estrutura mas não executava  
V2.5 = **IMPLEMENTAÇÃO COMPLETA** 🎉

---

## 🧪 Testar V2.5

```bash
# Suite completa de testes
cd tests/v25
bash test_all.sh

# Testar exemplos individuais
porto exemplos/v25/funcoes_completas.pt
porto exemplos/v25/fibonacci.pt
porto exemplos/v25/sistema_notas.pt
```

---

## 🤝 Contribuir

Contribuições são muito bem-vindas!

1. Fork o projeto
2. Crie uma branch (`git checkout -b feature/nova`)
3. Commit (`git commit -m 'Adiciona nova feature'`)
4. Push (`git push origin feature/nova`)
5. Abra um Pull Request

Veja [CONTRIBUTING.md](CONTRIBUTING.md) para mais detalhes.

### Roadmap V3.0

- [ ] Classes e objetos (OOP)
- [ ] Dicionários/mapas `{chave: valor}`
- [ ] Try/catch funcional
- [ ] Imports com escopo
- [ ] REPL interativo
- [ ] Debugger integrado
- [ ] Async/await
- [ ] Mais pacotes oficiais
- [ ] GUI toolkit
- [ ] Web framework

---

## 📝 Licença

MIT License - Código aberto e gratuito

Veja [LICENSE](LICENSE) para detalhes completos.

---

## 👨‍💻 Autor

**mista.lll** (Felipe605)

- 💬 Discord: **mista.lll**
- 🐦 Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)
- 📱 Reddit: [u/mistalll](https://reddit.com/u/mistalll)
- 💻 GitHub: [@Felipe605](https://github.com/Felipe605)
- 📧 Email: mistall900@gmail.com

---

## 🌟 Apoie o Projeto

- ⭐ **Dê uma estrela** no repositório
- 🐛 **Reporte bugs** via Issues
- 💡 **Sugira funcionalidades**
- 📢 **Compartilhe** com amigos
- 🤝 **Contribua** com código
- 💰 **Considere** fazer uma doação

---

## 📊 Estatísticas

![GitHub Stars](https://img.shields.io/github/stars/Felipe605/porto?style=social)
![GitHub Forks](https://img.shields.io/github/forks/Felipe605/porto?style=social)
![GitHub Issues](https://img.shields.io/github/issues/Felipe605/porto)
![GitHub Pull Requests](https://img.shields.io/github/issues-pr/Felipe605/porto)
![GitHub Last Commit](https://img.shields.io/github/last-commit/Felipe605/porto)

---

## 🎓 Aprenda Porto

### Tutoriais
- [Básico](./docs/BASICO.md) - Primeiros passos
- [Funções](./docs/FUNCOES.md) - Como criar funções
- [Arrays](./docs/ARRAYS.md) - Trabalhando com listas
- [Arquivos](./docs/ARQUIVOS.md) - Ler e escrever arquivos

### Exemplos Práticos
- Ver pasta [`exemplos/v25/`](./exemplos/v25)
- Todos os exemplos são executáveis
- Código comentado e explicado

### Comunidade
- Discord: Junte-se à comunidade Porto
- Reddit: r/porto (em breve)
- Telegram: Grupo Porto Brasil (em breve)

---

## 🏆 Conquistas

- 🥇 **Primeira** linguagem 100% em português para Termux
- 🎯 **Completamente funcional** - todos recursos implementados
- 🚀 **Open source** - código aberto desde o início
- 🇧🇷 **Feito no Brasil** - por brasileiros, para brasileiros
- 📦 **Sistema de pacotes** próprio e funcional
- 🤖 **Bots Discord** em português (único!)

---

<div align="center">

## 🇧🇷 PORTO V2.5 - TOTALMENTE FUNCIONAL! 🇧🇷

**Programar em português não é mais sonho - é realidade!**

**Porto v2.5.0** - Janeiro 2026

Criado com ❤️ por **mista.lll**

---

[⬆️ Voltar ao topo](#-porto---linguagem-de-programação-em-português)

[![Estrelas](https://img.shields.io/github/stars/Felipe605/porto?style=social)](https://github.com/Felipe605/porto/stargazers)
[![Forks](https://img.shields.io/github/forks/Felipe605/porto?style=social)](https://github.com/Felipe605/porto/network/members)

</div>

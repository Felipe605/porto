# 🇧🇷 Porto - Linguagem de Programação em Português

![Porto](https://img.shields.io/badge/Porto-v2.5.0-purple?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-Termux-blue?style=for-the-badge)

**A primeira linguagem de programação totalmente em português**

Criada por **mista.lll** (Felipe605)

🐦 Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)  
📱 Reddit: [u/mistalll](https://reddit.com/u/mistalll)  
💬 Discord: **mista.lll**

---

## 🎉 Porto V2.5 - TOTALMENTE FUNCIONAL!

### ✨ Novos Recursos (FUNCIONANDO!)

#### 1. **Funções com Parâmetros e Return**
```porto
funcao somar(a, b)
    retorna a + b
fimfuncao

variavel resultado = somar(10, 5)
escreva resultado  # 15

# Recursão funciona!
funcao fatorial(n)
    se n <= 1 entao
        retorna 1
    senao
        retorna n * fatorial(n - 1)
    fim
fimfuncao

escreva fatorial(5)  # 120
```

#### 2. **Arrays com Indexação**
```porto
variavel numeros = [10, 20, 30, 40, 50]

escreva numeros[0]  # 10
escreva numeros[2]  # 30

variavel nomes = ["Ana", "Bruno", "Carlos"]
escreva nomes[1]  # Bruno

# Tamanho do array
variavel tam = numeros.tamanho()
escreva tam  # 5
```

#### 3. **For Loops Completos**
```porto
# For numérico
para i de 1 ate 10 faca
    escreva i
fim

# For em array
variavel frutas = ["maçã", "banana", "laranja"]
para fruta em frutas faca
    escreva fruta
fim
```

#### 4. **String Methods**
```porto
variavel texto = "Porto"

escreva texto.tamanho()           # 5
escreva texto.maiuscula()         # PORTO
escreva texto.minuscula()         # porto
escreva texto.substring(0, 3)     # Por

# Concatenação
variavel msg = "Linguagem " + texto + " V2.5"
escreva msg  # Linguagem Porto V2.5
```

#### 5. **File I/O (Ler e Escrever Arquivos)**
```porto
# Escrever
variavel arq = abrir("dados.txt", "escrita")
arq.escrever("Olá, Porto!")
arq.fechar()

# Ler
variavel arq2 = abrir("dados.txt", "leitura")
variavel conteudo = arq2.ler()
escreva conteudo
arq2.fechar()
```

---

## 📦 Recursos Completos

| Recurso | Status |
|---------|--------|
| Variáveis | ✅ |
| Matemática | ✅ |
| Entrada/Saída | ✅ |
| Condicionais (se/senao) | ✅ |
| Loops (enquanto) | ✅ |
| **Funções** | ✅ **NOVO!** |
| **Arrays com []** | ✅ **NOVO!** |
| **For loops** | ✅ **NOVO!** |
| **String methods** | ✅ **NOVO!** |
| **File I/O** | ✅ **NOVO!** |
| Operadores lógicos | ✅ |
| Comentários | ✅ |
| Syntax highlighting | ✅ |
| Package manager | ✅ |

---

## 🚀 Instalação

```bash
git clone https://github.com/Felipe605/porto.git
cd porto
bash install_porto.sh
```

---

## 💡 Exemplos

### Fibonacci Recursivo
```porto
funcao fibonacci(n)
    se n <= 1 entao
        retorna n
    senao
        retorna fibonacci(n-1) + fibonacci(n-2)
    fim
fimfuncao

para i de 0 ate 10 faca
    escreva "F(" + i + ") = " + fibonacci(i)
fim
```

### Sistema de Notas
```porto
funcao calcular_media(notas)
    variavel soma = 0
    para i de 0 ate notas.tamanho() - 1 faca
        variavel soma = soma + notas[i]
    fim
    retorna soma / notas.tamanho()
fimfuncao

variavel notas_aluno = [8.5, 7.0, 9.0, 6.5]
variavel media = calcular_media(notas_aluno)

se media >= 7 entao
    escreva "Aprovado! Média: " + media
senao
    escreva "Reprovado! Média: " + media
fim
```

Mais exemplos em [`/exemplos/v25`](./exemplos/v25)

---

## 🆚 Comparação de Versões

| Recurso | V2.0 | V2.5 |
|---------|------|------|
| Funções | Estrutura | ✅ **Funciona!** |
| Arrays | Básico | ✅ **Com indexação!** |
| For loops | Estrutura | ✅ **Funciona!** |
| Strings | Básico | ✅ **Com métodos!** |
| File I/O | ❌ | ✅ **Completo!** |

---

## 🤝 Contribuir

Quer ajudar? Veja [CONTRIBUTING.md](CONTRIBUTING.md)

---

## 📝 Licença

MIT License - Por mista.lll (Felipe605)

---

## 👨‍💻 Autor

**mista.lll** (Felipe605)
- GitHub: [@Felipe605](https://github.com/Felipe605)
- Discord: **mista.lll**
- Twitter: [@MistaGuido75430](https://twitter.com/MistaGuido75430)
- Reddit: [u/mistalll](https://reddit.com/u/mistalll)

---

<div align="center">

**Porto V2.5 - Totalmente Funcional! 🎉**

🇧🇷 **Programar em português é realidade!** 🇧🇷

</div>

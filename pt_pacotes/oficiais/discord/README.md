# 📦 Discord - Pacote Porto

**Biblioteca para criar bots Discord em português!**

Primeira biblioteca Discord totalmente em PORTUGUÊS para criar bots.

## 🚀 Instalação

```bash
porto-pkg instalar discord
```

Ou manualmente:
```bash
cd pt_pacotes/oficiais/discord
bash instalar.sh
```

## 📖 Como Usar

### 1. Importar o pacote

```porto
importa "discord"
```

### 2. Configurar bot

```porto
discord.criar("SEU_TOKEN", "!")
```

### 3. Criar comandos

```porto
# Comando simples
discord.comando("ola", "Olá! Sou um bot em Porto!")

# Comando com lógica
discord.comando "calcular"
    variavel resultado = 10 + 5
    discord.responder(resultado)
fimcomando
```

### 4. Adicionar eventos

```porto
# Quando bot conectar
discord.ao_conectar
    escreva "Bot online!"
fimevento

# Quando receber mensagem
discord.ao_mensagem
    variavel autor = discord.autor_mensagem
    escreva autor
fimevento

# Quando alguém entrar
discord.ao_entrar_membro
    discord.enviar("#bem-vindo", "Bem-vindo!")
fimevento
```

### 5. Iniciar bot

```porto
discord.iniciar()
```

## 📝 Exemplo Completo

```porto
importa "discord"

# Configurar
discord.criar("MEU_TOKEN", "!")

# Comandos
discord.comando("ping", "Pong! 🏓")

discord.comando "ola"
    discord.responder("Olá! Sou um bot feito em PORTUGUÊS!")
fimcomando

discord.comando "contador"
    variavel i = 1
    enquanto i <= 5 faca
        discord.enviar(canal_atual, i)
        variavel i = i + 1
    fim
fimcomando

# Eventos
discord.ao_conectar
    escreva "✅ Bot conectado!"
fimevento

# Iniciar
discord.iniciar()
```

## 🔑 Como Pegar Token

1. Acesse: https://discord.com/developers/applications
2. Crie "New Application"
3. Vá em "Bot"
4. Clique "Add Bot"
5. Copie o Token
6. Em "Privileged Gateway Intents", ative:
   - MESSAGE CONTENT INTENT
   - SERVER MEMBERS INTENT

## 🔗 Convidar Bot

```
https://discord.com/oauth2/authorize?client_id=SEU_CLIENT_ID&permissions=8&scope=bot
```

Substitua `SEU_CLIENT_ID` pelo ID da sua aplicação.

## 📚 API Disponível

### Funções

- `discord.criar(token, prefixo)` - Configura bot
- `discord.comando(nome, resposta)` - Cria comando
- `discord.responder(mensagem)` - Responde mensagem
- `discord.enviar(canal, msg)` - Envia para canal
- `discord.iniciar()` - Inicia bot

### Eventos

- `discord.ao_conectar` - Quando conectar
- `discord.ao_mensagem` - Quando receber mensagem
- `discord.ao_entrar_membro` - Quando membro entrar
- `discord.ao_sair_membro` - Quando membro sair

### Variáveis de Contexto

- `discord.autor_mensagem` - Autor da mensagem atual
- `discord.mensagem_atual` - Conteúdo da mensagem
- `discord.canal_atual` - Canal da mensagem
- `discord.servidor_atual` - Servidor atual

## 🛠️ Requisitos

- Python 3.8+
- discord.py 2.0+
- Porto 2.0+

## 📦 Estrutura

```
discord/
├── package.json      # Metadados do pacote
├── main.pt           # Entry point
├── discord_core.py   # Core Python
├── funcoes.pt        # Funções helper
├── exemplo_uso.pt    # Exemplo
├── instalar.sh       # Instalador
└── README.md         # Documentação
```

## 🤝 Contribuir

Quer adicionar mais funcionalidades? Abra um PR!

## 📄 Licença

MIT - Felipe605 (Mista)

## 🔗 Links

- Porto: https://github.com/Felipe605/porto
- Discord.py: https://discordpy.readthedocs.io/
- Discord Developers: https://discord.com/developers/docs

---

**Feito com ❤️ em Português 🇧🇷**

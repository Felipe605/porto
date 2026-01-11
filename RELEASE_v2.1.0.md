# 🤖 Porto v2.1.0 - Pacote Discord

## 🎉 Novidade Épica!

Porto agora tem suporte oficial para criar **bots Discord em português**!

## ✨ Novo Pacote: Discord

Crie bots Discord usando a linguagem Porto, totalmente em português!

### Instalação

```bash
porto-pkg instalar discord
```

### Exemplo Rápido

```porto
importa "discord"

discord.criar("SEU_TOKEN", "!")

discord.comando("ola", "Olá! Sou um bot em português! 🇧🇷")
discord.comando("ping", "Pong! 🏓")

discord.comando "info"
    discord.responder("Bot feito com Porto!")
    discord.responder("Primeira linguagem em PT!")
fimcomando

discord.ao_conectar
    escreva "Bot online! ✅"
fimevento

discord.iniciar()
```

## 📦 O que vem no pacote?

- ✅ API completa em português
- ✅ Suporte a comandos customizados
- ✅ Sistema de eventos
- ✅ Bridge com discord.py
- ✅ Documentação completa
- ✅ Tutorial passo a passo
- ✅ Exemplo de bot funcional

## 📚 Documentação

- [README do Pacote](./pt_pacotes/oficiais/discord/README.md)
- [Tutorial Completo](./pt_pacotes/oficiais/discord/TUTORIAL.md)
- [Exemplo de Bot](./projetos/bot-discord-exemplo/meu_bot.pt)

## 🚀 Como Começar

1. Instale o pacote:
   ```bash
   porto-pkg instalar discord
   ```

2. Pegue um token Discord:
   https://discord.com/developers/applications

3. Crie seu bot em Porto!

4. Execute:
   ```bash
   porto meu_bot.pt
   ```

## 🌟 Por que isso é incrível?

- 🇧🇷 **Primeira linguagem em português com suporte a Discord**
- 🎓 **Perfeito para aprender** - Sintaxe em português
- 🚀 **Fácil de usar** - API simples e intuitiva
- 💪 **Poderoso** - Usa discord.py por baixo dos panos

## 📊 Estatísticas da v2.1.0

- **5 Pacotes Oficiais** (matematica, texto, entrada_saida, web, discord)
- **Sistema de Package Manager** funcional
- **Syntax Highlighting** integrado
- **Exemplos práticos** inclusos

## 🙏 Agradecimentos

Obrigado a todos que estão usando e apoiando o Porto!

**Programar em português é realidade!** 🇧🇷🚀

---

**Links:**
- [Documentação Discord](./pt_pacotes/oficiais/discord/)
- [Exemplo de Bot](./projetos/bot-discord-exemplo/)
- [Issues](https://github.com/Felipe605/porto/issues)
- [Contribuir](./CONTRIBUTING.md)

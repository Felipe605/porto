# 📚 Tutorial: Criando Seu Primeiro Bot Discord em Porto

## Passo 1: Criar Aplicação no Discord

1. Acesse https://discord.com/developers/applications
2. Clique "New Application"
3. Dê um nome (ex: "Meu Bot Porto")
4. Vá em "Bot" no menu lateral
5. Clique "Add Bot"
6. Copie o Token (guarde bem!)

## Passo 2: Configurar Permissões

1. Em "Privileged Gateway Intents", ative:
   - MESSAGE CONTENT INTENT ✅
   - SERVER MEMBERS INTENT ✅
2. Salve as mudanças

## Passo 3: Criar Seu Bot

Crie um arquivo `meu_bot.pt`:

```porto
importa "discord"

discord.criar("SEU_TOKEN", "!")

discord.comando("ola", "Olá do Porto!")

discord.iniciar()
```

## Passo 4: Executar

```bash
porto meu_bot.pt
```

## Passo 5: Convidar para Servidor

Use este link (substitua CLIENT_ID):
```
https://discord.com/oauth2/authorize?client_id=CLIENT_ID&permissions=8&scope=bot
```

Pronto! Seu bot está online! 🎉

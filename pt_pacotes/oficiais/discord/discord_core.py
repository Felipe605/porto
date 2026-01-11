#!/usr/bin/env python3
"""
Porto Discord Core
Núcleo da biblioteca Discord para Porto
"""

import discord
from discord.ext import commands
import asyncio
import json
import sys
import os

class PortoDiscordAPI:
    """API Discord para Porto"""
    
    def __init__(self):
        self.bot = None
        self.token = None
        self.prefix = "!"
        self.intents = discord.Intents.default()
        self.intents.message_content = True
        self.intents.members = True
        
        # Armazena comandos definidos em Porto
        self.comandos_porto = {}
        self.eventos_porto = {}
    
    def configurar(self, config_file):
        """Carrega configuração do bot"""
        with open(config_file, 'r', encoding='utf-8') as f:
            config = json.load(f)
        
        self.token = config.get('token')
        self.prefix = config.get('prefixo', '!')
        
        return self
    
    def criar_bot(self):
        """Cria instância do bot Discord"""
        self.bot = commands.Bot(
            command_prefix=self.prefix,
            intents=self.intents
        )
        
        self._registrar_eventos()
        return self
    
    def _registrar_eventos(self):
        """Registra eventos padrão do Discord"""
        
        @self.bot.event
        async def on_ready():
            print(f'✅ Bot {self.bot.user} conectado!')
            print(f'📊 {len(self.bot.guilds)} servidores')
            print(f'🤖 Prefixo: {self.prefix}')
            
            # Executa evento porto se existir
            if 'ao_conectar' in self.eventos_porto:
                await self._executar_evento_porto('ao_conectar', {})
        
        @self.bot.event
        async def on_message(message):
            # Ignora mensagens do bot
            if message.author == self.bot.user:
                return
            
            # Evento de mensagem em Porto
            if 'ao_mensagem' in self.eventos_porto:
                contexto = {
                    'autor': str(message.author),
                    'conteudo': message.content,
                    'canal': str(message.channel)
                }
                await self._executar_evento_porto('ao_mensagem', contexto)
            
            # Processa comandos
            await self.bot.process_commands(message)
        
        @self.bot.event
        async def on_member_join(member):
            """Quando alguém entra no servidor"""
            if 'ao_entrar_membro' in self.eventos_porto:
                contexto = {
                    'membro': str(member),
                    'servidor': str(member.guild)
                }
                await self._executar_evento_porto('ao_entrar_membro', contexto)
    
    async def _executar_evento_porto(self, evento, contexto):
        """Executa código Porto de um evento"""
        # Aqui seria a integração com interpretador Porto
        # Por enquanto só loga
        print(f"🔔 Evento: {evento}")
    
    def registrar_comando(self, nome, funcao_porto):
        """Registra comando Porto no bot"""
        
        async def comando_wrapper(ctx, *args):
            # Contexto para Porto
            contexto = {
                'autor': str(ctx.author),
                'canal': str(ctx.channel),
                'servidor': str(ctx.guild) if ctx.guild else 'DM',
                'argumentos': list(args)
            }
            
            # Executa código Porto
            resultado = await self._executar_codigo_porto(funcao_porto, contexto)
            
            if resultado:
                await ctx.send(resultado)
        
        # Registra no bot Discord
        self.bot.command(name=nome)(comando_wrapper)
        self.comandos_porto[nome] = funcao_porto
    
    async def _executar_codigo_porto(self, codigo, contexto):
        """Executa código Porto e retorna resultado"""
        # Aqui integraria com interpretador Porto
        # Por enquanto retorna placeholder
        return f"Executando comando Porto..."
    
    def adicionar_evento(self, tipo_evento, codigo_porto):
        """Adiciona handler de evento em Porto"""
        self.eventos_porto[tipo_evento] = codigo_porto
    
    def iniciar(self):
        """Inicia o bot"""
        if not self.token:
            print("❌ Token não configurado!")
            return
        
        if not self.bot:
            self.criar_bot()
        
        print("🚀 Iniciando bot Discord...")
        self.bot.run(self.token)


# CLI para usar via Porto
if __name__ == '__main__':
    import argparse
    
    parser = argparse.ArgumentParser(description='Porto Discord Core')
    parser.add_argument('--config', required=True, help='Arquivo de configuração')
    parser.add_argument('--script', help='Script Porto com comandos')
    
    args = parser.parse_args()
    
    api = PortoDiscordAPI()
    api.configurar(args.config)
    api.criar_bot()
    
    # Carrega script Porto se fornecido
    if args.script:
        # Aqui carregaria e processaria o script Porto
        pass
    
    api.iniciar()

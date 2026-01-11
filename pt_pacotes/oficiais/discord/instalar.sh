#!/bin/bash

echo "================================================"
echo "  Instalando Pacote Discord para Porto"
echo "================================================"

echo "[1/3] Verificando Python..."
if ! command -v python3 &> /dev/null; then
    echo "Instalando Python..."
    pkg install -y python
fi

echo "[2/3] Instalando discord.py..."
pip install discord.py

echo "[3/3] Configurando pacote..."
echo "✅ Pacote Discord instalado!"
echo ""
echo "Para usar:"
echo "  importa \"discord\""
echo ""
echo "Veja exemplo_uso.pt para aprender a criar bots!"

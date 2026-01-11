#!/bin/bash

echo "Digite seu usuário do GitHub:"
read USUARIO

echo "Adicionando remote..."
git remote add origin https://github.com/$USUARIO/porto.git

echo "Fazendo push..."
git push -u origin main
git push --tags

echo "✓ Código enviado para GitHub!"
echo "Acesse: https://github.com/$USUARIO/porto"

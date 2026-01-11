# 📥 Guia de Instalação do Porto

## Termux (Recomendado)

### Método 1: Clone + Install
```bash
git clone https://github.com/Felipe605/porto.git
cd porto
chmod +x install_porto.sh
bash install_porto.sh
```

### Método 2: Instalação Rápida
```bash
curl -fsSL https://raw.githubusercontent.com/Felipe605/porto/main/install_porto.sh | bash
```

## Verificação

```bash
porto --help
porto-pkg --help
```

## Problemas Comuns

### Erro: clang não encontrado
```bash
pkg install clang
```

### Erro: permissão negada
```bash
chmod +x install_porto.sh
```

## Atualização

```bash
cd porto
git pull
bash update_porto.sh
```

#!/bin/bash

echo "🧪 TESTANDO PORTO V2.5"
echo "================================"

cd "$(dirname "$0")"

tests=(
    "../../exemplos/v25/funcoes_completas.pt"
    "../../exemplos/v25/arrays_completos.pt"
    "../../exemplos/v25/for_completo.pt"
    "../../exemplos/v25/strings.pt"
    "../../exemplos/v25/fibonacci.pt"
    "../../exemplos/v25/sistema_notas.pt"
)

passed=0
failed=0

for test in "${tests[@]}"; do
    name=$(basename "$test")
    echo ""
    echo "▶ Testando $name..."
    echo "---"
    
    if porto "$test" 2>&1; then
        ((passed++))
        echo "---"
        echo "✅ $name PASSOU"
    else
        ((failed++))
        echo "---"
        echo "❌ $name FALHOU"
    fi
done

echo ""
echo "================================"
echo "📊 RESULTADO:"
echo "   ✅ Passaram: $passed"
echo "   ❌ Falharam: $failed"
echo "================================"

if [ $failed -eq 0 ]; then
    echo "🎉 TODOS OS TESTES PASSARAM!"
    exit 0
else
    echo "⚠️  Alguns testes falharam"
    exit 1
fi

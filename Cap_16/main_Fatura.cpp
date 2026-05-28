// Exercicio 16.13 - main_Fatura.cpp
#include <iostream>
#include "Fatura.h"
using namespace std;

void imprimirFatura(const Fatura &f) {
    cout << "  Peca: "        << f.getNumeroPeca()
         << "  Descr: "       << f.getDescricao() << "\n"
         << "  Qtd: "         << f.getQuantidade()
         << "  Preco unit: "  << f.getPrecoPorItem()
         << "  Total: "       << f.obterValorFatura() << endl;
}

int main() {
    // Fatura valida
    cout << "=== Fatura 1 (valores normais) ===" << endl;
    Fatura f1("P-1001", "Martelo de aco", 3, 25);
    imprimirFatura(f1);

    // Fatura com quantidade negativa (sera ajustada para 0)
    cout << "\n=== Fatura 2 (quantidade negativa: deve virar 0) ===" << endl;
    Fatura f2("P-1002", "Chave de fenda", -5, 12);
    imprimirFatura(f2);

    // Fatura com preco negativo (sera ajustado para 0)
    cout << "\n=== Fatura 3 (preco negativo: deve virar 0) ===" << endl;
    Fatura f3("P-1003", "Furadeira", 2, -30);
    imprimirFatura(f3);

    // Demonstrando setters
    cout << "\n>>> Atualizando f1 com novos valores..." << endl;
    f1.setQuantidade(10);
    f1.setPrecoPorItem(15);
    imprimirFatura(f1);

    return 0;
}

// Exercicio 17.8 - main_DateNext.cpp
#include <iostream>
#include "DateNext.h"
using namespace std;

void testar(const char *etiqueta, int m, int d, int y, int qtos) {
    cout << "\n=== " << etiqueta << " ===" << endl;
    DateNext data(m, d, y);
    cout << "Inicio: "; data.print(); cout << endl;
    for (int i = 0; i < qtos; ++i) {
        data.nextDay();
        cout << " nextDay #" << (i+1) << ": "; data.print(); cout << endl;
    }
}

int main() {
    // (a) Transicao de mes (fim de marco -> abril)
    testar("Transicao de mes (30/3 -> 1/4)", 3, 30, 2026, 3);

    // (b) Transicao de ano (fim de dezembro -> janeiro)
    testar("Transicao de ano (30/12 -> 1/1/2027)", 12, 30, 2026, 3);

    // Fevereiro em ano nao bissexto (28 dias)
    testar("Fevereiro nao bissexto (27/2/2025 -> 1/3)", 2, 27, 2025, 3);

    // Fevereiro em ano bissexto (29 dias)
    testar("Fevereiro bissexto (28/2/2024 -> 29/2 -> 1/3)", 2, 28, 2024, 2);

    // Testes de validacao no construtor
    cout << "\n=== Testes de validacao ===" << endl;
    DateNext invalida(13, 32, 2025);   // mes invalido, dia tambem
    cout << "Apos validacao: "; invalida.print(); cout << endl;

    return 0;
}

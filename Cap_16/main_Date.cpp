// Exercicio 16.15 - main_Date.cpp
#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    cout << "=== Data 1 (valida) ===" << endl;
    Date d1(5, 15, 2026);
    cout << "Data: "; d1.mostraData();

    cout << "\n=== Data 2 (mes invalido = 13) ===" << endl;
    Date d2(13, 25, 2025);
    cout << "Data: "; d2.mostraData();

    cout << "\n=== Data 3 (mes invalido = 0) ===" << endl;
    Date d3(0, 1, 2024);
    cout << "Data: "; d3.mostraData();

    cout << "\n>>> Atualizando d1 com setMes(7), setDia(4), setAno(2030)..."
         << endl;
    d1.setMes(7);
    d1.setDia(4);
    d1.setAno(2030);
    cout << "Data: "; d1.mostraData();

    cout << "\n>>> Tentando setMes(15) em d1 (invalido)..." << endl;
    d1.setMes(15);
    cout << "Data: "; d1.mostraData();

    return 0;
}

// Exercicio 22.7 - main_Array.cpp
#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    // === Instancia\c{a}o de Array<int, 5> -> usa o template GERAL ===
    cout << "=== Array<int, 5> (usa template geral) ===" << endl;
    Array<int, 5> arrInt;
    for (int i = 0; i < arrInt.tamanho(); ++i)
        arrInt[i] = (i + 1) * 10;        // 10, 20, 30, 40, 50
    arrInt.imprimir();

    // === Instancia\c{a}o de Array<double, 3> -> tambem geral ===
    cout << "\n=== Array<double, 3> (usa template geral) ===" << endl;
    Array<double, 3> arrDbl;
    arrDbl[0] = 1.5;
    arrDbl[1] = 2.5;
    arrDbl[2] = 3.5;
    arrDbl.imprimir();

    // === Instancia\c{a}o de Array<float, 4> -> usa a ESPECIALIZACAO ===
    cout << "\n=== Array<float, 4> (usa ESPECIALIZACAO!) ===" << endl;
    Array<float, 4> arrFloat;
    arrFloat[0] = 3.14159f;
    arrFloat[1] = 2.71828f;
    arrFloat[2] = 1.41421f;
    arrFloat[3] = 0.57721f;
    arrFloat.imprimir();

    // === Inspecionando: o tamanho eh conhecido em tempo de COMPILACAO ===
    cout << "\nTamanho de cada array:" << endl;
    cout << "  arrInt:   " << arrInt.tamanho()   << " elementos" << endl;
    cout << "  arrDbl:   " << arrDbl.tamanho()   << " elementos" << endl;
    cout << "  arrFloat: " << arrFloat.tamanho() << " elementos" << endl;

    return 0;
}

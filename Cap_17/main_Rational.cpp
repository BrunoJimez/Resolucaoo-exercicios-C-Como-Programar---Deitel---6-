// Exercicio 17.6 - main_Rational.cpp
#include <iostream>
#include "Rational.h"
using namespace std;

void mostrar(const char *label, const Rational &r) {
    cout << label << " = ";
    r.printFraction();
    cout << "  (";
    r.printFloatingPoint();
    cout << ")" << endl;
}

int main() {
    cout << "=== Teste da classe Rational ===" << endl;

    // Construtor com reducao automatica
    Rational r1(2, 4);          // deve virar 1/2
    Rational r2(3, 9);          // deve virar 1/3
    Rational r3;                // default: 0/1

    cout << "\nConstrutores (verifica reducao automatica):" << endl;
    mostrar("2/4 reduzido", r1);
    mostrar("3/9 reduzido", r2);
    mostrar("default     ", r3);

    cout << "\nOperacoes aritmeticas:" << endl;
    mostrar("r1 + r2", r1.add(r2));
    mostrar("r1 - r2", r1.subtract(r2));
    mostrar("r1 * r2", r1.multiply(r2));
    mostrar("r1 / r2", r1.divide(r2));

    // Casos com sinais negativos
    cout << "\nCom sinais negativos:" << endl;
    Rational r4(-6, 8);         // -3/4
    Rational r5(6, -8);         // -3/4 (sinal no num)
    mostrar("-6/8 ", r4);
    mostrar("6/-8 ", r5);

    return 0;
}

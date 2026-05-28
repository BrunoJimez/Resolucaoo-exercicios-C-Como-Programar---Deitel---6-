// Exercicio 19.10 - main_RationalNumber.cpp
#include <iostream>
#include "RationalNumber.h"
using namespace std;

int main() {
    cout << "=== Construtores: 2/4 e 3/9 sao reduzidos ===" << endl;
    RationalNumber r1(2, 4);
    RationalNumber r2(3, 9);
    cout << "2/4 -> " << r1 << endl;     // 1/2
    cout << "3/9 -> " << r2 << endl;     // 1/3

    cout << "\n=== Aritmetica ===" << endl;
    cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
    cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;
    cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
    cout << r1 << " / " << r2 << " = " << (r1 / r2) << endl;

    cout << "\n=== Comparacoes ===" << endl;
    RationalNumber a(1, 2);
    RationalNumber b(2, 4);                // mesma fracao reduzida que a
    RationalNumber c(1, 3);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "a == b ? " << (a == b ? "SIM" : "NAO") << endl;
    cout << "a != c ? " << (a != c ? "SIM" : "NAO") << endl;
    cout << "a >  c ? " << (a >  c ? "SIM" : "NAO") << "  (1/2 > 1/3)" << endl;
    cout << "a <  c ? " << (a <  c ? "SIM" : "NAO") << endl;
    cout << "a >= b ? " << (a >= b ? "SIM" : "NAO") << endl;
    cout << "c <= a ? " << (c <= a ? "SIM" : "NAO") << endl;

    cout << "\n=== Validacao: denominador 0 ===" << endl;
    RationalNumber bug(5, 0);
    cout << "5/0 -> " << bug << endl;

    cout << "\n=== Sinal sempre no numerador ===" << endl;
    RationalNumber neg(2, -5);
    cout << "2/-5 -> " << neg << endl;

    return 0;
}

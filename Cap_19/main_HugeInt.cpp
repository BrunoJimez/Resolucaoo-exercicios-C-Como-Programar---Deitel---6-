// Exercicio 19.9 - main_HugeInt.cpp
#include <iostream>
#include "HugeInt.h"
using namespace std;

int main() {
    cout << "=== Soma (livro) ===" << endl;
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;
    cout << "n1 = " << n1 << endl;
    cout << "n2 = " << n2 << endl;
    cout << "n3 = " << n3 << endl;
    cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
    cout << n3 << " + " << n4 << "\n  = " << (n3 + n4) << endl;

    // (c) Multiplicacao
    cout << "\n=== Multiplicacao ===" << endl;
    HugeInt a(123);
    HugeInt b(456);
    cout << a << " * " << b << " = " << (a * b) << "   (esperado 56088)" << endl;

    HugeInt grande("1000000000000");        // 10^12
    HugeInt outro("1000000000000");
    cout << grande << " * " << outro << "\n  = " << (grande * outro)
         << "   (esperado 10^24)" << endl;

    // (d) Divisao
    cout << "\n=== Divisao ===" << endl;
    HugeInt d1(1000);
    HugeInt d2(7);
    cout << d1 << " / " << d2 << " = " << (d1 / d2)
         << "   (esperado 142)" << endl;

    HugeInt d3("1000000");
    HugeInt d4(1000);
    cout << d3 << " / " << d4 << " = " << (d3 / d4)
         << "   (esperado 1000)" << endl;

    // (e) Relacionais
    cout << "\n=== Operadores relacionais ===" << endl;
    HugeInt x(100);
    HugeInt y(200);
    HugeInt z(100);
    cout << "x=" << x << " y=" << y << " z=" << z << endl;
    cout << "x == z ? " << (x == z ? "SIM" : "NAO") << endl;
    cout << "x != y ? " << (x != y ? "SIM" : "NAO") << endl;
    cout << "x <  y ? " << (x <  y ? "SIM" : "NAO") << endl;
    cout << "x >  y ? " << (x >  y ? "SIM" : "NAO") << endl;
    cout << "x <= z ? " << (x <= z ? "SIM" : "NAO") << endl;
    cout << "y >= x ? " << (y >= x ? "SIM" : "NAO") << endl;

    return 0;
}

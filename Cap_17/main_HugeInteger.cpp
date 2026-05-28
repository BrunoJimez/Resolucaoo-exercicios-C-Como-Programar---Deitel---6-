// Exercicio 17.14 - main_HugeInteger.cpp
#include <iostream>
#include "HugeInteger.h"
using namespace std;

void linha(const char *etiqueta, const HugeInteger &h) {
    cout << etiqueta;
    h.output();
    cout << endl;
}

int main() {
    // Numeros bem grandes, que ultrapassam long long (max ~ 9.2e18)
    HugeInteger a("12345678901234567890123456789012345");
    HugeInteger b("11111111111111111111111111111111111");
    HugeInteger c("99999999999999999999999999999999999");
    HugeInteger zero;

    cout << "=== Inteiros gigantes ===" << endl;
    linha("a    = ", a);
    linha("b    = ", b);
    linha("c    = ", c);
    linha("zero = ", zero);

    cout << "\n=== Operacoes aritmeticas ===" << endl;
    linha("a + b = ", a.add(b));
    linha("a - b = ", a.subtract(b));
    linha("c + 1 = ", c.add(HugeInteger("1")));

    cout << "\n=== Comparacoes ===" << endl;
    cout << "a == b ? " << (a.isEqualTo(b) ? "SIM" : "NAO") << endl;
    cout << "a != b ? " << (a.isNotEqualTo(b) ? "SIM" : "NAO") << endl;
    cout << "a >  b ? " << (a.isGreaterThan(b) ? "SIM" : "NAO") << endl;
    cout << "a <  b ? " << (a.isLessThan(b) ? "SIM" : "NAO") << endl;
    cout << "a >= b ? " << (a.isGreaterThanOrEqualTo(b) ? "SIM" : "NAO") << endl;
    cout << "a <= b ? " << (a.isLessThanOrEqualTo(b) ? "SIM" : "NAO") << endl;
    cout << "zero.isZero() ? " << (zero.isZero() ? "SIM" : "NAO") << endl;
    cout << "a.isZero()    ? " << (a.isZero()    ? "SIM" : "NAO") << endl;

    return 0;
}

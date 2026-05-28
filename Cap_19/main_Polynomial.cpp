// Exercicio 19.11 - main_Polynomial.cpp
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main() {
    // p1 = 3x^2 + 2x + 1
    Termo t1[] = {{3, 2}, {2, 1}, {1, 0}};
    Polynomial p1(t1, 3);
    cout << "p1 = " << p1 << endl;

    // p2 = x^3 - 4x + 7
    Termo t2[] = {{1, 3}, {-4, 1}, {7, 0}};
    Polynomial p2(t2, 3);
    cout << "p2 = " << p2 << endl;

    // p3 = 5x^2 - 2x + 3
    Termo t3[] = {{5, 2}, {-2, 1}, {3, 0}};
    Polynomial p3(t3, 3);
    cout << "p3 = " << p3 << endl;

    cout << "\n=== Soma ===" << endl;
    Polynomial soma = p1 + p2;
    cout << "p1 + p2 = " << soma << endl;
    // Esperado: x^3 + 3x^2 - 2x + 8

    Polynomial soma13 = p1 + p3;
    cout << "p1 + p3 = " << soma13 << "   (esperado: 8x^2 + 4)" << endl;

    cout << "\n=== Subtracao ===" << endl;
    Polynomial diff = p1 - p3;
    cout << "p1 - p3 = " << diff << "   (esperado: -2x^2 + 4x - 2)" << endl;

    cout << "\n=== Multiplicacao ===" << endl;
    // (3x^2+2x+1) * (5x^2-2x+3) =
    //   15x^4 - 6x^3 + 9x^2 + 10x^3 - 4x^2 + 6x + 5x^2 - 2x + 3 =
    //   15x^4 + 4x^3 + 10x^2 + 4x + 3
    Polynomial prod = p1 * p3;
    cout << "p1 * p3 = " << prod << endl;
    cout << "   (esperado: 15x^4 + 4x^3 + 10x^2 + 4x + 3)" << endl;

    cout << "\n=== Atribuicao composta ===" << endl;
    Polynomial q = p1;
    cout << "q = p1 = " << q << endl;

    q += p3;
    cout << "q += p3 => q = " << q << "   (= p1+p3)" << endl;

    q -= p3;
    cout << "q -= p3 => q = " << q << "   (= p1 novamente)" << endl;

    q *= p3;
    cout << "q *= p3 => q = " << q << "   (= p1*p3)" << endl;

    cout << "\n=== Atribuicao = ===" << endl;
    Polynomial r;
    r = p2;
    cout << "r (apos r = p2) = " << r << endl;

    cout << "\n=== setTermo ===" << endl;
    Polynomial s;
    s.setTermo(3,  4);
    s.setTermo(1, -1);
    s.setTermo(0,  6);
    cout << "s (4x^3 - x + 6) = " << s << endl;
    s.setTermo(1,  0);                 // remove o termo linear
    cout << "s apos setTermo(1, 0): " << s << "   (deve perder o x)" << endl;

    return 0;
}

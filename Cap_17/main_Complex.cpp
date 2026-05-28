// Exercicio 17.5 - main_Complex.cpp
#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
    Complex c1(3.5, 7.2);
    Complex c2(1.5, 2.0);
    Complex c3;                 // usa default: (0.0, 0.0)

    cout << "c1 = "; c1.print(); cout << endl;
    cout << "c2 = "; c2.print(); cout << endl;
    cout << "c3 = "; c3.print(); cout << " (default)" << endl;

    Complex soma = c1.add(c2);
    cout << "\nc1 + c2 = "; soma.print(); cout << endl;

    Complex diff = c1.subtract(c2);
    cout << "c1 - c2 = "; diff.print(); cout << endl;

    return 0;
}

// Exercicio 17.5 - Complex.cpp
#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double real, double imag)
    : parteReal(real), parteImaginaria(imag) {
}

Complex Complex::add(const Complex &outro) const {
    return Complex(parteReal + outro.parteReal,
                   parteImaginaria + outro.parteImaginaria);
}

Complex Complex::subtract(const Complex &outro) const {
    return Complex(parteReal - outro.parteReal,
                   parteImaginaria - outro.parteImaginaria);
}

void Complex::print() const {
    cout << "(" << parteReal << ", " << parteImaginaria << ")";
}

// Exercicio 19.8 - Complex.cpp
#include "Complex.h"
using namespace std;

Complex::Complex(double real, double imag)
    : parteReal(real), parteImaginaria(imag) {}

Complex Complex::operator+(const Complex &o) const {
    return Complex(parteReal + o.parteReal,
                   parteImaginaria + o.parteImaginaria);
}

Complex Complex::operator-(const Complex &o) const {
    return Complex(parteReal - o.parteReal,
                   parteImaginaria - o.parteImaginaria);
}

// (a+bi)*(c+di) = (ac - bd) + (ad + bc)*i
Complex Complex::operator*(const Complex &o) const {
    return Complex(parteReal * o.parteReal
                   - parteImaginaria * o.parteImaginaria,
                   parteReal * o.parteImaginaria
                   + parteImaginaria * o.parteReal);
}

bool Complex::operator==(const Complex &o) const {
    return parteReal == o.parteReal
        && parteImaginaria == o.parteImaginaria;
}

bool Complex::operator!=(const Complex &o) const {
    return !(*this == o);
}

// Funcao amiga: cout << c
ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.parteReal << ", " << c.parteImaginaria << ")";
    return out;
}

// Funcao amiga: cin >> c
// Espera entrada no formato "real imaginaria"
istream &operator>>(istream &in, Complex &c) {
    in >> c.parteReal >> c.parteImaginaria;
    return in;
}

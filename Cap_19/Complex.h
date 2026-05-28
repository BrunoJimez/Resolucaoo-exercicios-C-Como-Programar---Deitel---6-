// Exercicio 19.8 - Complex.h
// Classe Complex com sobrecarga total de operadores
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    // Funcoes amigas para entrada/saida
    friend std::ostream &operator<<(std::ostream &out, const Complex &c);
    friend std::istream &operator>>(std::istream &in,  Complex &c);
public:
    Complex(double real = 0.0, double imag = 0.0);

    Complex operator+(const Complex &o) const;
    Complex operator-(const Complex &o) const;
    Complex operator*(const Complex &o) const;   // (b) multiplicacao

    bool operator==(const Complex &o) const;     // (c) igualdade
    bool operator!=(const Complex &o) const;

private:
    double parteReal;
    double parteImaginaria;
};

#endif

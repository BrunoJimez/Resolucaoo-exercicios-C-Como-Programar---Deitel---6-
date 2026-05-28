// Exercicio 19.10 - RationalNumber.h
// Fracao com sobrecarga total de operadores: + - * / == != < > <= >=
// e << >> para I/O
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
    friend std::ostream &operator<<(std::ostream &out, const RationalNumber &r);
    friend std::istream &operator>>(std::istream &in,  RationalNumber &r);
public:
    RationalNumber(int numerador = 0, int denominador = 1);

    // Aritmeticos
    RationalNumber operator+(const RationalNumber &o) const;
    RationalNumber operator-(const RationalNumber &o) const;
    RationalNumber operator*(const RationalNumber &o) const;
    RationalNumber operator/(const RationalNumber &o) const;

    // Relacionais e igualdade
    bool operator==(const RationalNumber &o) const;
    bool operator!=(const RationalNumber &o) const;
    bool operator< (const RationalNumber &o) const;
    bool operator> (const RationalNumber &o) const;
    bool operator<=(const RationalNumber &o) const;
    bool operator>=(const RationalNumber &o) const;

private:
    int num;   // numerador (carrega o sinal)
    int den;   // denominador (sempre > 0)

    void reduzir();
    static int mdc(int a, int b);
};

#endif

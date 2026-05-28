// Exercicio 19.9 - HugeInt.h
// Inteiros gigantes (30 digitos) com: + (livro), * /, ==, !=, <, >, <=, >=
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);
public:
    static const int digits = 30;

    HugeInt(long valor = 0);                  // converte de long
    HugeInt(const std::string &numero);       // converte de string

    HugeInt operator+(const HugeInt &op2) const;
    HugeInt operator+(int op2) const;
    HugeInt operator+(const std::string &op2) const;

    // (c) Multiplicacao e (d) divisao
    HugeInt operator*(const HugeInt &op2) const;
    HugeInt operator/(const HugeInt &op2) const;

    // Subtracao (necessaria para a divisao)
    HugeInt operator-(const HugeInt &op2) const;

    // (e) Relacionais e igualdade
    bool operator==(const HugeInt &o) const;
    bool operator!=(const HugeInt &o) const;
    bool operator< (const HugeInt &o) const;
    bool operator> (const HugeInt &o) const;
    bool operator<=(const HugeInt &o) const;
    bool operator>=(const HugeInt &o) const;

    bool isZero() const;

private:
    short integer[digits];   // integer[digits-1] = unidade
};

#endif

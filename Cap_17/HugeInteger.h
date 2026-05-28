// Exercicio 17.14 - HugeInteger.h
// Inteiro de ate 40 digitos armazenado em array
#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H

#include <string>

class HugeInteger {
public:
    static const int TAMANHO = 40;

    HugeInteger();                          // construtor: zera tudo
    explicit HugeInteger(const std::string &s);   // a partir de string

    void input();                           // le do teclado
    void output() const;                    // imprime sem zeros a esquerda

    HugeInteger add(const HugeInteger &outro) const;
    HugeInteger subtract(const HugeInteger &outro) const;

    // Funcoes-predicado de comparacao
    bool isEqualTo(const HugeInteger &o) const;
    bool isNotEqualTo(const HugeInteger &o) const;
    bool isGreaterThan(const HugeInteger &o) const;
    bool isLessThan(const HugeInteger &o) const;
    bool isGreaterThanOrEqualTo(const HugeInteger &o) const;
    bool isLessThanOrEqualTo(const HugeInteger &o) const;
    bool isZero() const;

private:
    // digitos[0] = unidade, digitos[1] = dezena, ...
    int digitos[TAMANHO];
};

#endif

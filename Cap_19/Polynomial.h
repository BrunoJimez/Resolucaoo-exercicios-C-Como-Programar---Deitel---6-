// Exercicio 19.11 - Polynomial.h
// Polinomio armazenado como array dinamico de termos.
// Cada termo tem coeficiente (double) e expoente (int).
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

struct Termo {
    double coeficiente;
    int    expoente;
};

class Polynomial {
    friend std::ostream &operator<<(std::ostream &out, const Polynomial &p);
public:
    Polynomial();                                    // construtor default
    Polynomial(const Termo *termos, int qtd);        // por array de termos
    Polynomial(const Polynomial &outro);             // copia
    ~Polynomial();                                   // destrutor

    // Setters / getters
    int    getNumeroDeTermos() const;
    double getCoeficiente(int i) const;
    int    getExpoente(int i) const;
    void   setTermo(int expoente, double coeficiente);

    // Operadores aritmeticos
    Polynomial operator+(const Polynomial &o) const;
    Polynomial operator-(const Polynomial &o) const;
    Polynomial operator*(const Polynomial &o) const;

    // Atribuicao e compostos
    const Polynomial &operator=(const Polynomial &o);
    const Polynomial &operator+=(const Polynomial &o);
    const Polynomial &operator-=(const Polynomial &o);
    const Polynomial &operator*=(const Polynomial &o);

private:
    Termo *termos;       // array dinamico de termos (somente termos != 0)
    int    qtd;          // quantos termos sao usados

    void normalizar();   // remove termos com coeficiente 0 e ordena
};

#endif

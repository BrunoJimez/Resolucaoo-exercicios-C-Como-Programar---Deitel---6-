// Exercicio 17.5 - Complex.h
// Classe Complex para aritmetica com numeros complexos
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
public:
    // Construtor com valores default
    Complex(double real = 0.0, double imag = 0.0);

    Complex add(const Complex &outro) const;
    Complex subtract(const Complex &outro) const;

    void print() const;     // imprime no formato (a, b)

private:
    double parteReal;
    double parteImaginaria;
};

#endif

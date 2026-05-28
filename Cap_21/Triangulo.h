// Exercicio 21.13 - Triangulo.h
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

class Triangulo : public FormaBidimensional {
public:
    Triangulo(double base, double altura);

    double retArea() const override;
    void   print()   const override;

private:
    double base;
    double altura;
};

#endif

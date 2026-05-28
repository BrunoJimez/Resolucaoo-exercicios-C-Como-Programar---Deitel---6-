// Exercicio 21.13 - Circulo.h
#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

class Circulo : public FormaBidimensional {
public:
    Circulo(double raio);

    double retArea() const override;
    void   print()   const override;

private:
    double raio;
};

#endif

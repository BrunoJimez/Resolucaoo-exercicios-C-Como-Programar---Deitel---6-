// Exercicio 21.13 - Quadrado.h
#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

class Quadrado : public FormaBidimensional {
public:
    Quadrado(double lado);

    double retArea() const override;
    void   print()   const override;

private:
    double lado;
};

#endif

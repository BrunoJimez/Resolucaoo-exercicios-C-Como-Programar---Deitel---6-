// Exercicio 21.13 - Cubo.h
#ifndef CUBO_H
#define CUBO_H

#include "FormaTridimensional.h"

class Cubo : public FormaTridimensional {
public:
    Cubo(double lado);

    double retArea()   const override;
    double retVolume() const override;
    void   print()     const override;

private:
    double lado;
};

#endif

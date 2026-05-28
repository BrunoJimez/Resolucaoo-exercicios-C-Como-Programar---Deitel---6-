// Exercicio 21.13 - Esfera.h
#ifndef ESFERA_H
#define ESFERA_H

#include "FormaTridimensional.h"

class Esfera : public FormaTridimensional {
public:
    Esfera(double raio);

    double retArea()   const override;
    double retVolume() const override;
    void   print()     const override;

private:
    double raio;
};

#endif

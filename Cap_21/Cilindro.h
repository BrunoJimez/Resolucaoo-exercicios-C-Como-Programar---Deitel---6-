// Exercicio 21.13 - Cilindro.h
#ifndef CILINDRO_H
#define CILINDRO_H

#include "FormaTridimensional.h"

class Cilindro : public FormaTridimensional {
public:
    Cilindro(double raio, double altura);

    double retArea()   const override;
    double retVolume() const override;
    void   print()     const override;

private:
    double raio;
    double altura;
};

#endif

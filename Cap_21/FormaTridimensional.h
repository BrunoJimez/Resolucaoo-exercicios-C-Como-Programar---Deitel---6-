// Exercicio 21.13 - FormaTridimensional.h
// Camada intermediaria ABSTRATA: adiciona retArea() e retVolume()
#ifndef FORMA3D_H
#define FORMA3D_H

#include "Forma.h"

class FormaTridimensional : public Forma {
public:
    FormaTridimensional(const std::string &nome);

    virtual double retArea()   const = 0;
    virtual double retVolume() const = 0;
};

#endif

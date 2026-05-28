// Exercicio 21.13 - FormaBidimensional.h
// Camada intermediaria ABSTRATA: adiciona retArea()
#ifndef FORMA2D_H
#define FORMA2D_H

#include "Forma.h"

class FormaBidimensional : public Forma {
public:
    FormaBidimensional(const std::string &nome);

    virtual double retArea() const = 0;   // virtual pura: ainda abstrata
};

#endif

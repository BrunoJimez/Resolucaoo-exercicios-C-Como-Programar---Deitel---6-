// Exercicio 21.17 - Bicicleta.h
// Bicicleta: emissao basicamente ZERO em uso.
// Modelamos a emissao de fabricacao amortizada pela vida util.
#ifndef BICICLETA_H
#define BICICLETA_H

#include "EmissaoCarbono.h"
#include <string>

class Bicicleta : public EmissaoCarbono {
public:
    Bicicleta(const std::string &modelo, int vidaUtilEmAnos);

    std::string getModelo() const;
    int getVidaUtil()       const;

    // ~250 kg CO2 para fabricar uma bicicleta moderna,
    // amortizada pela vida util => emissao "anual" pequena
    double retEmissaoCarbono() const override;
    std::string descricao() const override;

private:
    std::string modelo;
    int vidaUtilEmAnos;
};

#endif

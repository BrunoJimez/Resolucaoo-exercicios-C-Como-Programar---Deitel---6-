// Exercicio 21.17 - Carro.h
// Carro: emissao baseada em km rodados / consumo (km por litro).
#ifndef CARRO_H
#define CARRO_H

#include "EmissaoCarbono.h"
#include <string>

class Carro : public EmissaoCarbono {
public:
    Carro(const std::string &modelo,
          double kmPorAno, double kmPorLitro);

    std::string getModelo() const;
    double getKmPorAno()    const;
    double getKmPorLitro()  const;

    // ~2.3 kg de CO2 por litro de gasolina queimado
    double retEmissaoCarbono() const override;
    std::string descricao() const override;

private:
    std::string modelo;
    double kmPorAno;
    double kmPorLitro;
};

#endif

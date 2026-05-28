// Exercicio 21.17 - Predio.h
// Predio: emissao baseada em consumo eletrico anual.
#ifndef PREDIO_H
#define PREDIO_H

#include "EmissaoCarbono.h"
#include <string>

class Predio : public EmissaoCarbono {
public:
    Predio(const std::string &endereco,
           double consumoEletricoAnualKWh);

    void setConsumo(double c);
    double getConsumo() const;
    std::string getEndereco() const;

    // Fator US: ~0.4 kg CO2 por kWh (EPA, media de rede eletrica EUA)
    double retEmissaoCarbono() const override;
    std::string descricao() const override;

private:
    std::string endereco;
    double consumoEletricoAnualKWh;
};

#endif

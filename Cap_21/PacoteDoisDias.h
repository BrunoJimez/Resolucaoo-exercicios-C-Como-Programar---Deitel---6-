// Exercicio 21.15 - PacoteDoisDias.h
#ifndef PACOTEDOISDIAS_H
#define PACOTEDOISDIAS_H

#include "Pacote.h"

class PacoteDoisDias : public Pacote {
public:
    PacoteDoisDias(const std::string &nR, const std::string &eR,
                   const std::string &cR, const std::string &esR,
                   const std::string &cepR,
                   const std::string &nD, const std::string &eD,
                   const std::string &cD, const std::string &esD,
                   const std::string &cepD,
                   double pesoG, double custoPorG,
                   double taxaFixaEntrega);

    void   setTaxaFixaEntrega(double t);
    double getTaxaFixaEntrega() const;

    double calculaCusto() const override;   // agora com override!

private:
    double taxaFixaEntrega;
};

#endif

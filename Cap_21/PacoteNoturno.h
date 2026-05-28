// Exercicio 21.15 - PacoteNoturno.h
#ifndef PACOTENOTURNO_H
#define PACOTENOTURNO_H

#include "Pacote.h"

class PacoteNoturno : public Pacote {
public:
    PacoteNoturno(const std::string &nR, const std::string &eR,
                  const std::string &cR, const std::string &esR,
                  const std::string &cepR,
                  const std::string &nD, const std::string &eD,
                  const std::string &cD, const std::string &esD,
                  const std::string &cepD,
                  double pesoG, double custoPorG,
                  double taxaAdicionalPorG);

    void   setTaxaAdicional(double t);
    double getTaxaAdicional() const;

    double calculaCusto() const override;

private:
    double taxaAdicionalPorGrama;
};

#endif

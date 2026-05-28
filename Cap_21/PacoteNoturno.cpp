// Exercicio 21.15 - PacoteNoturno.cpp
#include "PacoteNoturno.h"

PacoteNoturno::PacoteNoturno(
        const std::string &nR, const std::string &eR,
        const std::string &cR, const std::string &esR, const std::string &cepR,
        const std::string &nD, const std::string &eD,
        const std::string &cD, const std::string &esD, const std::string &cepD,
        double p, double c, double ta)
    : Pacote(nR, eR, cR, esR, cepR, nD, eD, cD, esD, cepD, p, c) {
    setTaxaAdicional(ta);
}

void PacoteNoturno::setTaxaAdicional(double t) {
    taxaAdicionalPorGrama = (t >= 0) ? t : 0;
}
double PacoteNoturno::getTaxaAdicional() const { return taxaAdicionalPorGrama; }

double PacoteNoturno::calculaCusto() const {
    return peso * (custoPorGrama + taxaAdicionalPorGrama);
}

// Exercicio 21.15 - PacoteDoisDias.cpp
#include "PacoteDoisDias.h"

PacoteDoisDias::PacoteDoisDias(
        const std::string &nR, const std::string &eR,
        const std::string &cR, const std::string &esR, const std::string &cepR,
        const std::string &nD, const std::string &eD,
        const std::string &cD, const std::string &esD, const std::string &cepD,
        double p, double c, double tf)
    : Pacote(nR, eR, cR, esR, cepR, nD, eD, cD, esD, cepD, p, c) {
    setTaxaFixaEntrega(tf);
}

void PacoteDoisDias::setTaxaFixaEntrega(double t) {
    taxaFixaEntrega = (t >= 0) ? t : 0;
}
double PacoteDoisDias::getTaxaFixaEntrega() const { return taxaFixaEntrega; }

double PacoteDoisDias::calculaCusto() const {
    return Pacote::calculaCusto() + taxaFixaEntrega;
}

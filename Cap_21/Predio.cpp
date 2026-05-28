// Exercicio 21.17 - Predio.cpp
#include <sstream>
#include "Predio.h"
using namespace std;

Predio::Predio(const string &e, double c) : endereco(e) {
    setConsumo(c);
}

void Predio::setConsumo(double c) {
    consumoEletricoAnualKWh = (c >= 0) ? c : 0;
}
double Predio::getConsumo() const { return consumoEletricoAnualKWh; }
string Predio::getEndereco() const { return endereco; }

double Predio::retEmissaoCarbono() const {
    // ~0.4 kg de CO2 por kWh (fator medio EUA)
    return consumoEletricoAnualKWh * 0.4;
}

string Predio::descricao() const {
    ostringstream oss;
    oss << "Predio em " << endereco
        << " (consumo " << consumoEletricoAnualKWh << " kWh/ano)";
    return oss.str();
}

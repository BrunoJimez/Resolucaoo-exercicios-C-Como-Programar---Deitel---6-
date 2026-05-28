// Exercicio 21.17 - Carro.cpp
#include <sstream>
#include "Carro.h"
using namespace std;

Carro::Carro(const string &m, double kma, double kpl)
    : modelo(m),
      kmPorAno(kma >= 0 ? kma : 0),
      kmPorLitro(kpl > 0 ? kpl : 1) {}

string Carro::getModelo()     const { return modelo; }
double Carro::getKmPorAno()   const { return kmPorAno; }
double Carro::getKmPorLitro() const { return kmPorLitro; }

double Carro::retEmissaoCarbono() const {
    double litrosAno = kmPorAno / kmPorLitro;
    return litrosAno * 2.3;     // 2.3 kg CO2 por litro de gasolina
}

string Carro::descricao() const {
    ostringstream oss;
    oss << "Carro " << modelo
        << " (" << kmPorAno << " km/ano, "
        << kmPorLitro << " km/L)";
    return oss.str();
}

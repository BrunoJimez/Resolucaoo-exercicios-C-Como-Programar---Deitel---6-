// Exercicio 21.17 - Bicicleta.cpp
#include <sstream>
#include "Bicicleta.h"
using namespace std;

Bicicleta::Bicicleta(const string &m, int v)
    : modelo(m), vidaUtilEmAnos(v > 0 ? v : 1) {}

string Bicicleta::getModelo() const { return modelo; }
int Bicicleta::getVidaUtil() const { return vidaUtilEmAnos; }

double Bicicleta::retEmissaoCarbono() const {
    // 250 kg CO2 de fabricacao, amortizado pela vida util
    return 250.0 / vidaUtilEmAnos;
}

string Bicicleta::descricao() const {
    ostringstream oss;
    oss << "Bicicleta " << modelo
        << " (vida util " << vidaUtilEmAnos << " anos)";
    return oss.str();
}

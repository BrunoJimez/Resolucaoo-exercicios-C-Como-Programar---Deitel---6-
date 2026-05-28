// Exercicio 21.13 - Circulo.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Circulo.h"
using namespace std;

Circulo::Circulo(double r)
    : FormaBidimensional("Circulo"), raio(r >= 0 ? r : 0) {}

double Circulo::retArea() const {
    return M_PI * raio * raio;
}

void Circulo::print() const {
    cout << "Circulo de raio " << fixed << setprecision(2) << raio;
}

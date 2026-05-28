// Exercicio 21.13 - Cilindro.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Cilindro.h"
using namespace std;

Cilindro::Cilindro(double r, double h)
    : FormaTridimensional("Cilindro"),
      raio(r >= 0 ? r : 0), altura(h >= 0 ? h : 0) {}

// Area total: 2 * pi * r^2 (duas bases) + 2 * pi * r * h (lateral)
double Cilindro::retArea() const {
    return 2 * M_PI * raio * (raio + altura);
}
// Volume: pi * r^2 * h
double Cilindro::retVolume() const {
    return M_PI * raio * raio * altura;
}

void Cilindro::print() const {
    cout << "Cilindro raio=" << fixed << setprecision(2) << raio
         << " altura=" << altura;
}

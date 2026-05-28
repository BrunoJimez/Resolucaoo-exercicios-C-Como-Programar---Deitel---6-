// Exercicio 21.13 - Esfera.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Esfera.h"
using namespace std;

Esfera::Esfera(double r)
    : FormaTridimensional("Esfera"), raio(r >= 0 ? r : 0) {}

// Area da superficie: 4 * pi * r^2
double Esfera::retArea() const {
    return 4 * M_PI * raio * raio;
}
// Volume: (4/3) * pi * r^3
double Esfera::retVolume() const {
    return (4.0 / 3.0) * M_PI * raio * raio * raio;
}

void Esfera::print() const {
    cout << "Esfera de raio " << fixed << setprecision(2) << raio;
}

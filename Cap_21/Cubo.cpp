// Exercicio 21.13 - Cubo.cpp
#include <iostream>
#include <iomanip>
#include "Cubo.h"
using namespace std;

Cubo::Cubo(double l)
    : FormaTridimensional("Cubo"), lado(l >= 0 ? l : 0) {}

// 6 faces quadradas
double Cubo::retArea()   const { return 6 * lado * lado; }
double Cubo::retVolume() const { return lado * lado * lado; }

void Cubo::print() const {
    cout << "Cubo de lado " << fixed << setprecision(2) << lado;
}

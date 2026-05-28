// Exercicio 21.13 - Quadrado.cpp
#include <iostream>
#include <iomanip>
#include "Quadrado.h"
using namespace std;

Quadrado::Quadrado(double l)
    : FormaBidimensional("Quadrado"), lado(l >= 0 ? l : 0) {}

double Quadrado::retArea() const { return lado * lado; }

void Quadrado::print() const {
    cout << "Quadrado de lado " << fixed << setprecision(2) << lado;
}

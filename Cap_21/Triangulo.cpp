// Exercicio 21.13 - Triangulo.cpp
#include <iostream>
#include <iomanip>
#include "Triangulo.h"
using namespace std;

Triangulo::Triangulo(double b, double h)
    : FormaBidimensional("Triangulo"),
      base(b >= 0 ? b : 0), altura(h >= 0 ? h : 0) {}

double Triangulo::retArea() const { return 0.5 * base * altura; }

void Triangulo::print() const {
    cout << "Triangulo base=" << fixed << setprecision(2) << base
         << " altura=" << altura;
}

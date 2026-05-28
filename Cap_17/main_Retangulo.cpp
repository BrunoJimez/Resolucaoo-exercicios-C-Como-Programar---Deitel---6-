// Exercicio 17.11 - main_Retangulo.cpp
#include <iostream>
#include <iomanip>
#include "Retangulo.h"
using namespace std;

void exibir(const char *etiqueta, const Retangulo &r) {
    cout << etiqueta
         << "  Comp=" << r.getComprimento()
         << "  Larg=" << r.getLargura()
         << "  Perimetro=" << r.perimetro()
         << "  Area=" << r.area() << endl;
}

int main() {
    cout << fixed << setprecision(2);

    cout << "=== Construtores ===" << endl;
    Retangulo r0;                  // default 1x1
    exibir("Default:    ", r0);

    Retangulo r1(5.0, 3.0);        // valido
    exibir("5x3:        ", r1);

    cout << "\n=== Validacao ===" << endl;
    Retangulo r2(25.0, 5.0);       // comprimento invalido
    exibir("(25,5):     ", r2);

    Retangulo r3(-1.0, -2.0);      // ambos invalidos
    exibir("(-1,-2):    ", r3);

    cout << "\n=== Setter direto ===" << endl;
    r1.setComprimento(100.0);       // invalido
    r1.setLargura(7.5);             // valido
    exibir("Apos sets:  ", r1);

    return 0;
}

// Exercicio 19.8 - main_Complex.cpp
#include <iostream>
#include <sstream>
#include "Complex.h"
using namespace std;

int main() {
    Complex x;                       // (0, 0)
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    // Sobrecarga de << - sintaxe natural com cout
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    // Sobrecarga de + e cadeia de << em uma linha
    x = y + z;
    cout << "\nx = y + z:" << endl;
    cout << x << " = " << y << " + " << z << endl;

    // Sobrecarga de -
    x = y - z;
    cout << "\nx = y - z:" << endl;
    cout << x << " = " << y << " - " << z << endl;

    // (b) Sobrecarga de *
    // (4.3 + 8.2i) * (3.3 + 1.1i) = (4.3*3.3 - 8.2*1.1) + (4.3*1.1 + 8.2*3.3)i
    //                              = (14.19 - 9.02) + (4.73 + 27.06)i
    //                              = (5.17, 31.79)
    x = y * z;
    cout << "\nx = y * z:" << endl;
    cout << x << " = " << y << " * " << z << endl;

    // (c) Comparacoes
    cout << "\n=== Comparacoes ===" << endl;
    Complex w(4.3, 8.2);    // identico a y
    cout << "y = " << y << ", w = " << w << endl;
    cout << "y == w ? " << (y == w ? "SIM" : "NAO") << endl;
    cout << "y != w ? " << (y != w ? "SIM" : "NAO") << endl;
    cout << "y == z ? " << (y == z ? "SIM" : "NAO") << endl;
    cout << "y != z ? " << (y != z ? "SIM" : "NAO") << endl;

    // Sobrecarga de >> usando stringstream para simular entrada
    cout << "\n=== Teste de operator>> (extracao de stream) ===" << endl;
    Complex c;
    istringstream entrada("2.5 -1.7");
    entrada >> c;
    cout << "Apos >> lendo '2.5 -1.7': c = " << c << endl;

    return 0;
}

// Exercicio 17.12 - main_RetanguloAvancado.cpp
#include <iostream>
#include <iomanip>
#include "RetanguloAvancado.h"
using namespace std;

void exibir(const char *etiqueta, const RetanguloAvancado &r) {
    cout << etiqueta << endl;
    cout << "  Cantos: (" << r.getX1() << "," << r.getY1() << "), ("
         << r.getX2() << "," << r.getY2() << "), ("
         << r.getX3() << "," << r.getY3() << "), ("
         << r.getX4() << "," << r.getY4() << ")" << endl;
    cout << "  Comprimento=" << r.comprimento()
         << "  Largura="     << r.largura() << endl;
    cout << "  Perimetro="   << r.perimetro()
         << "  Area="        << r.area()
         << "  Quadrado=" << (r.quadrado() ? "SIM" : "NAO") << endl;
}

int main() {
    cout << fixed << setprecision(2);

    cout << "=== Construtor default (unitario) ===" << endl;
    RetanguloAvancado r0;
    exibir("Default:", r0);

    cout << "\n=== Retangulo 5x3, canto inferior em (1,2) ===" << endl;
    RetanguloAvancado r1(1,2, 6,2, 6,5, 1,5);
    exibir("5x3:", r1);

    cout << "\n=== Quadrado 4x4 ===" << endl;
    RetanguloAvancado r2(0,0, 4,0, 4,4, 0,4);
    exibir("4x4:", r2);

    cout << "\n=== Coordenada fora do 1o quadrante (-1, 0) ===" << endl;
    RetanguloAvancado r3(-1,0, 4,0, 4,3, -1,3);
    exibir("Apos correcao:", r3);

    cout << "\n=== Nao forma retangulo (alterada) ===" << endl;
    RetanguloAvancado r4(0,0, 5,0, 4,3, 0,3);
    exibir("Apos correcao:", r4);

    return 0;
}

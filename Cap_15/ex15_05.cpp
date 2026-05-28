// Exercicio 15.5 - Area de um circulo com funcao inline
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

// Funcao inline que calcula a area de um circulo
inline double circleArea(const double radius) {
    return PI * pow(radius, 2);
}

int main() {
    double r;

    cout << "Digite o raio do circulo: ";
    cin  >> r;

    cout << "A area do circulo com raio " << r
         << " e " << circleArea(r) << endl;

    return 0;
}

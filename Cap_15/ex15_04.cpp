// Exercicio 15.4 - Volume de uma esfera com funcao inline
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

// Funcao inline que calcula o volume de uma esfera
inline double sphereVolume(const double radius) {
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

int main() {
    double radiusValue;

    cout << "Digite o raio da esfera: ";
    cin  >> radiusValue;

    cout << "Volume da esfera com raio " << radiusValue
         << " e " << sphereVolume(radiusValue) << endl;

    return 0;
}

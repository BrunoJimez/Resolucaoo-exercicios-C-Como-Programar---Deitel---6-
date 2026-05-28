// Exercicio 15.8 - Template de funcao "min"
#include <iostream>
using namespace std;

// Template de funcao para retornar o menor de dois valores
template <typename T>
T minimo(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    // Teste com inteiros
    int    i1 = 47, i2 = 23;
    cout << "min(" << i1 << ", " << i2 << ") = " << minimo(i1, i2) << endl;

    // Teste com numeros de ponto flutuante
    double d1 = 3.14, d2 = 2.71;
    cout << "min(" << d1 << ", " << d2 << ") = " << minimo(d1, d2) << endl;

    // Teste com caracteres
    char c1 = 'M', c2 = 'A';
    cout << "min('" << c1 << "', '" << c2 << "') = '" << minimo(c1, c2)
         << "'" << endl;

    return 0;
}

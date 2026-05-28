// Exercicio 15.9 - Template de funcao "max"
#include <iostream>
using namespace std;

// Template de funcao para retornar o maior de dois valores
template <typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Teste com inteiros
    int    i1 = 47, i2 = 23;
    cout << "max(" << i1 << ", " << i2 << ") = " << maximo(i1, i2) << endl;

    // Teste com numeros de ponto flutuante
    double d1 = 3.14, d2 = 2.71;
    cout << "max(" << d1 << ", " << d2 << ") = " << maximo(d1, d2) << endl;

    // Teste com caracteres
    char c1 = 'M', c2 = 'A';
    cout << "max('" << c1 << "', '" << c2 << "') = '" << maximo(c1, c2)
         << "'" << endl;

    return 0;
}

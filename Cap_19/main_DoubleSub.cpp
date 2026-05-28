// Exercicio 19.7 - main_DoubleSub.cpp
#include <iostream>
#include "DoubleSubscriptedArray.h"
using namespace std;

int main() {
    cout << "=== Construtor (3 linhas x 5 colunas, todos zero) ===" << endl;
    DoubleSubscriptedArray a(3, 5);
    cout << a;

    cout << "\n=== Atribuindo valores via operator(linha, coluna) ===" << endl;
    int valor = 1;
    for (int i = 0; i < a.getLinhas(); ++i)
        for (int j = 0; j < a.getColunas(); ++j)
            a(i, j) = valor++;
    cout << a;

    cout << "\n=== Acessando a(1, 3) ===" << endl;
    cout << "a(1, 3) = " << a(1, 3) << endl;

    cout << "\n=== Modificando a(2, 0) = 99 ===" << endl;
    a(2, 0) = 99;
    cout << a;

    cout << "\n=== Teste de == e construtor de copia ===" << endl;
    DoubleSubscriptedArray b(a);                  // copia
    cout << "b (copia de a):" << endl << b;
    cout << "a == b ? " << (a == b ? "SIM" : "NAO") << endl;
    cout << "a != b ? " << (a != b ? "SIM" : "NAO") << endl;

    b(0, 0) = 777;
    cout << "\nApos b(0,0)=777:" << endl;
    cout << "a == b ? " << (a == b ? "SIM" : "NAO") << endl;

    cout << "\n=== Teste de atribuicao (=) com tamanhos diferentes ===" << endl;
    DoubleSubscriptedArray c(2, 2);
    c = a;
    cout << "c apos c = a (c agora tem 3x5):" << endl << c;

    return 0;
}

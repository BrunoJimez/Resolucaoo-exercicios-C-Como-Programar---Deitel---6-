// Exercicio 22.6 (Cenario B) - isEqualTo_classeSem.cpp
// Mostra que SEM operator==, a classe NAO COMPILA com isEqualTo.
//
// Para reproduzir o erro do livro, basta DESCOMENTAR a linha indicada.
// O codigo abaixo permanece compilavel sem ele (so referencia o tipo).

#include <iostream>
#include <string>
using namespace std;

class Ponto {
public:
    Ponto(double x = 0, double y = 0) : x(x), y(y) {}
    // SEM operator==
private:
    double x, y;
};

template <typename T>
bool isEqualTo(const T &a, const T &b) {
    return a == b;     // chamara operator== de T
}

int main() {
    Ponto p1(1.0, 2.0);
    Ponto p2(1.0, 2.0);

    // A linha abaixo NAO COMPILA porque Ponto nao define operator==
    // Para reproduzir o erro: descomente a linha:
    //
    // cout << isEqualTo(p1, p2) << endl;
    //
    // Mensagem do g++:
    //   error: no match for 'operator==' (operand types are 'const Ponto'
    //   and 'const Ponto')
    //   note: in instantiation of 'bool isEqualTo(const T&, const T&)
    //   [with T = Ponto]'

    cout << "(Cenario B - compila apenas porque a chamada esta comentada.)\n";
    cout << "Pontos criados; sem operator==, isEqualTo nao pode instanciar.\n";

    // Para evitar warning de variavel nao usada:
    (void)p1; (void)p2;
    return 0;
}

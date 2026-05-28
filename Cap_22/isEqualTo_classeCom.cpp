// Exercicio 22.6 (Cenario C) - isEqualTo_classeCom.cpp
// AGORA com operator== sobrecarregado, isEqualTo COMPILA E FUNCIONA.

#include <iostream>
using namespace std;

class Ponto {
public:
    Ponto(double x = 0, double y = 0) : x(x), y(y) {}

    // Sobrecarga de operator==
    bool operator==(const Ponto &outro) const {
        return x == outro.x && y == outro.y;
    }
private:
    double x, y;
};

template <typename T>
bool isEqualTo(const T &a, const T &b) {
    return a == b;
}

int main() {
    cout << boolalpha;

    Ponto p1(1.0, 2.0);
    Ponto p2(1.0, 2.0);
    Ponto p3(3.0, 4.0);

    cout << "=== Cenario C: classe Ponto AGORA com operator== ===" << endl;
    cout << "isEqualTo(p1, p2) = " << isEqualTo(p1, p2)
         << "   (esperado true: ambos (1,2))" << endl;
    cout << "isEqualTo(p1, p3) = " << isEqualTo(p1, p3)
         << "   (esperado false)" << endl;
    cout << "isEqualTo(p2, p2) = " << isEqualTo(p2, p2)
         << "   (esperado true)" << endl;

    return 0;
}

// Exercicio 22.6 (Cenario A) - isEqualTo_primitivos.cpp
// Template isEqualTo testado com tipos primitivos
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
bool isEqualTo(const T &a, const T &b) {
    return a == b;
}

int main() {
    cout << boolalpha;

    cout << "=== Testes com tipos primitivos ===" << endl;
    cout << "isEqualTo(10, 10)      = " << isEqualTo(10, 10) << endl;
    cout << "isEqualTo(10, 20)      = " << isEqualTo(10, 20) << endl;
    cout << "isEqualTo(3.14, 3.14)  = " << isEqualTo(3.14, 3.14) << endl;
    cout << "isEqualTo('a', 'a')    = " << isEqualTo('a', 'a') << endl;
    cout << "isEqualTo('a', 'b')    = " << isEqualTo('a', 'b') << endl;

    // string da biblioteca padrao tem operator==
    string s1 = "Ola";
    string s2 = "Ola";
    string s3 = "Mundo";
    cout << "isEqualTo(s1, s2)      = " << isEqualTo(s1, s2) << endl;
    cout << "isEqualTo(s1, s3)      = " << isEqualTo(s1, s3) << endl;

    return 0;
}

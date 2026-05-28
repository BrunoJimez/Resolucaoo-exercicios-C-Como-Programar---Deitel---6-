// Exercicio 15.6 - Comparacao entre passagem por valor e passagem por referencia
#include <iostream>
using namespace std;

// (a) Passagem por valor: recebe copia, triplica e retorna o novo valor
int tripleByValue(int x) {
    x *= 3;
    return x;
}

// (b) Passagem por referencia: triplica o valor original atraves do alias
void tripleByReference(int &x) {
    x *= 3;
}

int main() {
    int count = 10;

    cout << "Antes de chamar tripleByValue:     count = " << count << endl;
    int resultado = tripleByValue(count);
    cout << "Apos chamar tripleByValue:         count = " << count
         << "  (retorno = " << resultado << ")" << endl;
    cout << "  --> Observe que count NAO mudou.\n" << endl;

    count = 10;  // reinicia para a segunda demonstracao
    cout << "Antes de chamar tripleByReference: count = " << count << endl;
    tripleByReference(count);
    cout << "Apos chamar tripleByReference:     count = " << count << endl;
    cout << "  --> Observe que count FOI modificado." << endl;

    return 0;
}

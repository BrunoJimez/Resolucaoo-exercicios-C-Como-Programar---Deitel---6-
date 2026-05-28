// Exercicio 16.12 - main_Account.cpp
// Programa de teste da classe Account
#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    // Cria duas contas: uma com saldo valido, outra com saldo invalido
    cout << "Criando conta1 com saldo inicial 100..." << endl;
    Account conta1(100);

    cout << "\nCriando conta2 com saldo inicial -50 (invalido)..." << endl;
    Account conta2(-50);

    cout << "\nSaldos iniciais:" << endl;
    cout << "  conta1.getBalance() = " << conta1.getBalance() << endl;
    cout << "  conta2.getBalance() = " << conta2.getBalance() << endl;

    // Testa credit
    cout << "\n>>> conta1.credit(50)" << endl;
    conta1.credit(50);
    cout << "Saldo da conta1: " << conta1.getBalance() << endl;

    cout << "\n>>> conta2.credit(200)" << endl;
    conta2.credit(200);
    cout << "Saldo da conta2: " << conta2.getBalance() << endl;

    // Testa debit (valor valido)
    cout << "\n>>> conta1.debit(30)" << endl;
    conta1.debit(30);
    cout << "Saldo da conta1: " << conta1.getBalance() << endl;

    // Testa debit (valor excede o saldo)
    cout << "\n>>> conta1.debit(500)  (excede o saldo!)" << endl;
    conta1.debit(500);
    cout << "Saldo da conta1: " << conta1.getBalance() << endl;

    return 0;
}

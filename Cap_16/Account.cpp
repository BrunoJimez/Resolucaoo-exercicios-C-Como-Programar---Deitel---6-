// Exercicio 16.12 - Account.cpp
#include <iostream>
#include "Account.h"
using namespace std;

// Construtor: valida o saldo inicial
Account::Account(int saldoInicial) {
    if (saldoInicial >= 0) {
        balance = saldoInicial;
    } else {
        balance = 0;
        cout << "Erro: saldo inicial invalido (" << saldoInicial
             << "). Saldo definido como 0." << endl;
    }
}

void Account::credit(int valor) {
    balance += valor;
}

void Account::debit(int valor) {
    if (valor > balance) {
        cout << "Valor do debito superior ao saldo da conta" << endl;
    } else {
        balance -= valor;
    }
}

int Account::getBalance() const {
    return balance;
}

// Exercicio 21.16 - Conta.cpp
#include <iostream>
#include "Conta.h"
using namespace std;

Conta::Conta(double saldoInicial) {
    if (saldoInicial >= 0.0) saldo = saldoInicial;
    else {
        saldo = 0.0;
        cout << "Erro: saldo inicial invalido. Saldo = 0.\n";
    }
}

void Conta::creditar(double valor) { saldo += valor; }

bool Conta::debitar(double valor) {
    if (valor > saldo) {
        cout << "Valor do debito superior ao saldo da conta\n";
        return false;
    }
    saldo -= valor;
    return true;
}

double Conta::retSaldo() const { return saldo; }

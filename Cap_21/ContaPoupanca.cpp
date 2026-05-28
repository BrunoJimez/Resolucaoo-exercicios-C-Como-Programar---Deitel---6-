// Exercicio 21.16 - ContaPoupanca.cpp
#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(double saldoInicial, double t)
    : Conta(saldoInicial) {
    setTaxaJuros(t);
}

void ContaPoupanca::setTaxaJuros(double t) {
    taxaJurosAnual = (t >= 0.0) ? t : 0.0;
}
double ContaPoupanca::getTaxaJuros() const { return taxaJurosAnual; }

double ContaPoupanca::calculaJuros() const {
    return saldo * taxaJurosAnual;
}

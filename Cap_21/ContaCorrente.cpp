// Exercicio 21.16 - ContaCorrente.cpp
#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(double saldoInicial, double t)
    : Conta(saldoInicial) {
    setTaxaTransacao(t);
}

void ContaCorrente::setTaxaTransacao(double t) {
    taxaPorTransacao = (t >= 0.0) ? t : 0.0;
}
double ContaCorrente::getTaxaTransacao() const { return taxaPorTransacao; }

void ContaCorrente::creditar(double valor) {
    Conta::creditar(valor);
    saldo -= taxaPorTransacao;
}

bool ContaCorrente::debitar(double valor) {
    bool ok = Conta::debitar(valor);
    if (ok) saldo -= taxaPorTransacao;
    return ok;
}

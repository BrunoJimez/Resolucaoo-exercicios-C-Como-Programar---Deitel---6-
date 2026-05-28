// Exercicio 21.16 - ContaPoupanca.h
#ifndef CONTAPOUPANCA21_H
#define CONTAPOUPANCA21_H

#include "Conta.h"

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(double saldoInicial, double taxaJurosAnual);

    void   setTaxaJuros(double t);
    double getTaxaJuros() const;
    double calculaJuros() const;

private:
    double taxaJurosAnual;
};

#endif

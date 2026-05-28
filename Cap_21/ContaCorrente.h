// Exercicio 21.16 - ContaCorrente.h
#ifndef CONTACORRENTE21_H
#define CONTACORRENTE21_H

#include "Conta.h"

class ContaCorrente : public Conta {
public:
    ContaCorrente(double saldoInicial, double taxaTransacao);

    void   setTaxaTransacao(double t);
    double getTaxaTransacao() const;

    void creditar(double valor) override;
    bool debitar(double valor) override;

private:
    double taxaPorTransacao;
};

#endif

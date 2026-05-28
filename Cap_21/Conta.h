// Exercicio 21.16 - Conta.h
// Agora com virtual em creditar() e debitar() para suportar
// polimorfismo dinamico nas derivadas.
#ifndef CONTA_H
#define CONTA_H

class Conta {
public:
    Conta(double saldoInicial);
    virtual ~Conta() {}

    virtual void creditar(double valor);
    virtual bool debitar(double valor);     // true = sucesso
    double retSaldo() const;

protected:
    double saldo;
};

#endif

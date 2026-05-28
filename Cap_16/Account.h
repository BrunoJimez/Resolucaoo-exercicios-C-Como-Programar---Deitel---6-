// Exercicio 16.12 - Account.h
// Declaracao da classe Account
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    // Construtor recebe saldo inicial e valida-o
    Account(int saldoInicial);

    // Credita um valor ao saldo
    void credit(int valor);

    // Debita um valor do saldo (validando se ha fundos)
    void debit(int valor);

    // Retorna o saldo atual
    int getBalance() const;

private:
    int balance;   // saldo da conta
};

#endif

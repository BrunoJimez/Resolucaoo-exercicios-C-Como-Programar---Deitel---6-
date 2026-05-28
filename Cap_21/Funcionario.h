// Exercicio 21.12 - Funcionario.h
// Classe-base ABSTRATA: tem funcao virtual pura earnings().
// Inclui dataNascimento (acrescimo do exercicio 21.12).
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include "Date.h"

class Funcionario {
public:
    Funcionario(const std::string &primeiroNome,
                const std::string &sobrenome,
                const std::string &cpf,
                const Date &dataNascimento);

    virtual ~Funcionario() {}     // destrutor virtual (Sec. 21.9)

    void setPrimeiroNome(const std::string &p);
    std::string getPrimeiroNome() const;
    void setSobrenome(const std::string &s);
    std::string getSobrenome() const;
    void setCPF(const std::string &c);
    std::string getCPF() const;

    const Date &getDataNascimento() const;

    // === FUNCAO VIRTUAL PURA ===
    // Cada derivada concreta deve implementar sua propria formula
    virtual double earnings() const = 0;

    // virtual nao-pura: derivadas podem sobrepor para refinar
    virtual void print() const;

private:
    std::string primeiroNome;
    std::string sobrenome;
    std::string cpf;
    Date dataNascimento;
};

#endif

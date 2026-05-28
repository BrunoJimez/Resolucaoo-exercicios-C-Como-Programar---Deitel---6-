// Exercicio 16.14 - Empregado.h
#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <string>

class Empregado {
public:
    Empregado(std::string primeiroNome, std::string sobrenome,
              int salarioMensal);

    void setPrimeiroNome(std::string n);
    std::string getPrimeiroNome() const;

    void setSobrenome(std::string s);
    std::string getSobrenome() const;

    // O setter valida: se nao positivo, define 0
    void setSalarioMensal(int s);
    int getSalarioMensal() const;

private:
    std::string primeiroNome;
    std::string sobrenome;
    int salarioMensal;
};

#endif

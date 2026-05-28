// Exercicio 21.12 - Funcionario.cpp
#include "Funcionario.h"
using namespace std;

Funcionario::Funcionario(const string &p, const string &s,
                         const string &c, const Date &nasc)
    : primeiroNome(p), sobrenome(s), cpf(c), dataNascimento(nasc) {}

void Funcionario::setPrimeiroNome(const string &p) { primeiroNome = p; }
string Funcionario::getPrimeiroNome() const { return primeiroNome; }
void Funcionario::setSobrenome(const string &s) { sobrenome = s; }
string Funcionario::getSobrenome() const { return sobrenome; }
void Funcionario::setCPF(const string &c) { cpf = c; }
string Funcionario::getCPF() const { return cpf; }

const Date &Funcionario::getDataNascimento() const { return dataNascimento; }

void Funcionario::print() const {
    cout << primeiroNome << " " << sobrenome
         << "\n  CPF: " << cpf
         << "\n  Nascimento: " << dataNascimento;
}

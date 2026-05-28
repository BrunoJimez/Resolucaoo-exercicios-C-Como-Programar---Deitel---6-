// Exercicio 16.14 - Empregado.cpp
#include "Empregado.h"
using namespace std;

Empregado::Empregado(string pn, string sn, int salario)
    : primeiroNome(pn), sobrenome(sn) {
    setSalarioMensal(salario);   // usa setter para validar
}

void Empregado::setPrimeiroNome(string n) { primeiroNome = n; }
string Empregado::getPrimeiroNome() const { return primeiroNome; }

void Empregado::setSobrenome(string s) { sobrenome = s; }
string Empregado::getSobrenome() const { return sobrenome; }

void Empregado::setSalarioMensal(int s) {
    salarioMensal = (s > 0) ? s : 0;
}
int Empregado::getSalarioMensal() const { return salarioMensal; }

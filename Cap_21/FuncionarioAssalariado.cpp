// Exercicio 21.12 - FuncionarioAssalariado.cpp
#include <iostream>
#include <iomanip>
#include "FuncionarioAssalariado.h"
using namespace std;

FuncionarioAssalariado::FuncionarioAssalariado(
        const string &p, const string &s, const string &c,
        const Date &nasc, double salario)
    : Funcionario(p, s, c, nasc) {
    setSalarioSemanal(salario);
}

void FuncionarioAssalariado::setSalarioSemanal(double s) {
    salarioSemanal = (s >= 0) ? s : 0;
}
double FuncionarioAssalariado::getSalarioSemanal() const {
    return salarioSemanal;
}

// 4 semanas por mes (aproximacao did\'atica)
double FuncionarioAssalariado::earnings() const {
    return salarioSemanal * 4;
}

void FuncionarioAssalariado::print() const {
    cout << "Assalariado: ";
    Funcionario::print();
    cout << "\n  Salario semanal: R$ "
         << fixed << setprecision(2) << salarioSemanal;
}

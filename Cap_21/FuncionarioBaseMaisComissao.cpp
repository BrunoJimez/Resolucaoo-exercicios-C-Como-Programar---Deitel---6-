// Exercicio 21.12 - FuncionarioBaseMaisComissao.cpp
#include <iostream>
#include <iomanip>
#include "FuncionarioBaseMaisComissao.h"
using namespace std;

FuncionarioBaseMaisComissao::FuncionarioBaseMaisComissao(
        const string &p, const string &s, const string &c,
        const Date &nasc, double v, double t, double sb)
    : FuncionarioComissao(p, s, c, nasc, v, t) {
    setSalarioBase(sb);
}

void FuncionarioBaseMaisComissao::setSalarioBase(double sb) {
    salarioBase = (sb >= 0) ? sb : 0;
}
double FuncionarioBaseMaisComissao::getSalarioBase() const {
    return salarioBase;
}

// Chama o earnings() da base via :: para reusar a logica de comissao
double FuncionarioBaseMaisComissao::earnings() const {
    return FuncionarioComissao::earnings() + salarioBase;
}

void FuncionarioBaseMaisComissao::print() const {
    cout << "Base+Comissao: ";
    Funcionario::print();
    cout << "\n  Vendas: R$ "
         << fixed << setprecision(2) << getVendasBrutas()
         << ", taxa: " << getTaxaComissao()
         << "\n  Salario base: R$ " << salarioBase;
}

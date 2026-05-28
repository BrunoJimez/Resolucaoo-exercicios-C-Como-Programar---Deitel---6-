// Exercicio 21.12 - FuncionarioComissao.cpp
#include <iostream>
#include <iomanip>
#include "FuncionarioComissao.h"
using namespace std;

FuncionarioComissao::FuncionarioComissao(
        const string &p, const string &s, const string &c,
        const Date &nasc, double v, double t)
    : Funcionario(p, s, c, nasc) {
    setVendasBrutas(v);
    setTaxaComissao(t);
}

void FuncionarioComissao::setVendasBrutas(double v) {
    vendasBrutas = (v >= 0) ? v : 0;
}
double FuncionarioComissao::getVendasBrutas() const { return vendasBrutas; }

void FuncionarioComissao::setTaxaComissao(double t) {
    taxaComissao = (t > 0 && t < 1) ? t : 0;
}
double FuncionarioComissao::getTaxaComissao() const { return taxaComissao; }

double FuncionarioComissao::earnings() const {
    return vendasBrutas * taxaComissao;
}

void FuncionarioComissao::print() const {
    cout << "Comissionado: ";
    Funcionario::print();
    cout << "\n  Vendas: R$ "
         << fixed << setprecision(2) << vendasBrutas
         << ", taxa: " << taxaComissao;
}

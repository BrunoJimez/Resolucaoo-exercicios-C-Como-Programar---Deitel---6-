// Exercicio 21.12 - FuncionarioHorista.cpp
#include <iostream>
#include <iomanip>
#include "FuncionarioHorista.h"
using namespace std;

FuncionarioHorista::FuncionarioHorista(
        const string &p, const string &s, const string &c,
        const Date &nasc, double sh, double hs)
    : Funcionario(p, s, c, nasc) {
    setSalarioPorHora(sh);
    setHoras(hs);
}

void FuncionarioHorista::setSalarioPorHora(double s) {
    salarioPorHora = (s >= 0) ? s : 0;
}
double FuncionarioHorista::getSalarioPorHora() const { return salarioPorHora; }

void FuncionarioHorista::setHoras(double h) {
    horasSemanais = (h >= 0 && h <= 168) ? h : 0;
}
double FuncionarioHorista::getHoras() const { return horasSemanais; }

// Padrao do livro: horas alem de 40 (por semana) recebem 1.5x.
// Multiplicamos por 4 para o mes.
double FuncionarioHorista::earnings() const {
    double semanal;
    if (horasSemanais <= 40)
        semanal = salarioPorHora * horasSemanais;
    else
        semanal = 40 * salarioPorHora
                  + (horasSemanais - 40) * salarioPorHora * 1.5;
    return semanal * 4;
}

void FuncionarioHorista::print() const {
    cout << "Horista: ";
    Funcionario::print();
    cout << "\n  Salario/hora: R$ "
         << fixed << setprecision(2) << salarioPorHora
         << ", horas semanais: " << horasSemanais;
}

// Exercicio 16.14 - main_Empregado.cpp
#include <iostream>
#include "Empregado.h"
using namespace std;

void exibirEmpregado(const Empregado &e) {
    cout << "  Nome:    " << e.getPrimeiroNome() << " " << e.getSobrenome()
         << "\n  Salario mensal: " << e.getSalarioMensal()
         << "\n  Salario anual:  " << e.getSalarioMensal() * 12 << endl;
}

int main() {
    // Cria dois empregados
    Empregado emp1("Ana", "Silva", 3500);
    Empregado emp2("Carlos", "Pereira", 4200);

    cout << "=== Antes do aumento ===" << endl;
    cout << "\n-- Empregado 1 --" << endl;
    exibirEmpregado(emp1);
    cout << "\n-- Empregado 2 --" << endl;
    exibirEmpregado(emp2);

    // Aplica aumento de 10% a cada empregado
    // (truncamento inteiro: salario * 110 / 100)
    emp1.setSalarioMensal(emp1.getSalarioMensal() * 110 / 100);
    emp2.setSalarioMensal(emp2.getSalarioMensal() * 110 / 100);

    cout << "\n=== Apos aumento de 10% ===" << endl;
    cout << "\n-- Empregado 1 --" << endl;
    exibirEmpregado(emp1);
    cout << "\n-- Empregado 2 --" << endl;
    exibirEmpregado(emp2);

    // Testa validacao com salario negativo
    cout << "\n>>> Tentando definir salario negativo em emp1..." << endl;
    emp1.setSalarioMensal(-1000);
    cout << "Salario apos tentativa invalida: "
         << emp1.getSalarioMensal() << endl;

    return 0;
}

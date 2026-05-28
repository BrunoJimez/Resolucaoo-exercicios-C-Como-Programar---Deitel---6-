// Exercicio 16.16 - main_FrequenciaCardiaca.cpp
#include <iostream>
#include "FrequenciaCardiaca.h"
using namespace std;

int main() {
    string pnome, snome;
    int dia, mes, ano;

    cout << "=== Calculadora de Frequencia Cardiaca ===" << endl;
    cout << "Primeiro nome: ";
    cin  >> pnome;
    cout << "Sobrenome: ";
    cin  >> snome;
    cout << "Data de nascimento (dia mes ano): ";
    cin  >> dia >> mes >> ano;

    FrequenciaCardiaca pessoa(pnome, snome, dia, mes, ano);

    cout << "\n--- Dados da pessoa ---" << endl;
    cout << "Nome: " << pessoa.getPrimeiroNome()
         << " " << pessoa.getSobrenome() << endl;
    cout << "Data de nascimento: "
         << pessoa.getDiaNascimento() << "/"
         << pessoa.getMesNascimento() << "/"
         << pessoa.getAnoNascimento() << endl;

    cout << "\n--- Frequencia ideal ---" << endl;
    pessoa.obterFrequenciaIdeal();

    return 0;
}

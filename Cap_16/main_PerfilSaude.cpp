// Exercicio 16.17 - main_PerfilSaude.cpp
#include <iostream>
#include <iomanip>
#include "PerfilSaude.h"
using namespace std;

int main() {
    string pnome, snome, sx;
    int dia, mes, ano, alt, peso;

    cout << "=== Perfil de Saude ===" << endl;
    cout << "Primeiro nome: ";   cin >> pnome;
    cout << "Sobrenome: ";       cin >> snome;
    cout << "Sexo (M/F): ";      cin >> sx;
    cout << "Data de nascimento (dia mes ano): ";
    cin  >> dia >> mes >> ano;
    cout << "Altura (em cm): ";  cin >> alt;
    cout << "Peso (em kg): ";    cin >> peso;

    PerfilSaude pessoa(pnome, snome, sx, dia, mes, ano, alt, peso);

    cout << "\n--- Dados Pessoais ---" << endl;
    cout << "Nome: " << pessoa.getPrimeiroNome()
         << " " << pessoa.getSobrenome() << endl;
    cout << "Sexo: " << pessoa.getSexo() << endl;
    cout << "Data de nascimento: "
         << pessoa.getDiaNascimento() << "/"
         << pessoa.getMesNascimento() << "/"
         << pessoa.getAnoNascimento() << endl;
    cout << "Altura: " << pessoa.getAltura() << " cm" << endl;
    cout << "Peso:   " << pessoa.getPeso()   << " kg" << endl;

    cout << "\n--- IMC ---" << endl;
    cout << fixed << setprecision(2);
    cout << "IMC = " << pessoa.obterIMC() << " kg/m^2" << endl;
    pessoa.exibirTabelaIMC();

    cout << "\n--- Frequencia Cardiaca ---" << endl;
    pessoa.obterFrequenciaIdeal();

    return 0;
}

// Exercicio 16.17 - PerfilSaude.cpp
#include <iostream>
#include "PerfilSaude.h"
using namespace std;

PerfilSaude::PerfilSaude(string pn, string sn, string sx,
                         int dn, int mn, int an,
                         int alt, int peso)
    : primeiroNome(pn), sobrenome(sn), sexo(sx),
      diaNascimento(dn), mesNascimento(mn), anoNascimento(an),
      alturaCm(alt), pesoKg(peso) {
}

void PerfilSaude::setPrimeiroNome(string n) { primeiroNome = n; }
string PerfilSaude::getPrimeiroNome() const { return primeiroNome; }

void PerfilSaude::setSobrenome(string s) { sobrenome = s; }
string PerfilSaude::getSobrenome() const { return sobrenome; }

void PerfilSaude::setSexo(string s) { sexo = s; }
string PerfilSaude::getSexo() const { return sexo; }

void PerfilSaude::setDiaNascimento(int d) { diaNascimento = d; }
int  PerfilSaude::getDiaNascimento() const { return diaNascimento; }

void PerfilSaude::setMesNascimento(int m) { mesNascimento = m; }
int  PerfilSaude::getMesNascimento() const { return mesNascimento; }

void PerfilSaude::setAnoNascimento(int a) { anoNascimento = a; }
int  PerfilSaude::getAnoNascimento() const { return anoNascimento; }

void PerfilSaude::setAltura(int cm) { alturaCm = cm; }
int  PerfilSaude::getAltura() const { return alturaCm; }

void PerfilSaude::setPeso(int kg) { pesoKg = kg; }
int  PerfilSaude::getPeso() const { return pesoKg; }

int PerfilSaude::obterIdade() const {
    int diaAtual, mesAtual, anoAtual;
    cout << "Digite a data atual (dia mes ano): ";
    cin  >> diaAtual >> mesAtual >> anoAtual;

    int idade = anoAtual - anoNascimento;
    if (mesAtual < mesNascimento ||
        (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        --idade;
    }
    return idade;
}

int PerfilSaude::obterFrequenciaMaxima() const {
    return 220 - obterIdade();
}

void PerfilSaude::obterFrequenciaIdeal() const {
    int maxima = obterFrequenciaMaxima();
    int idealMin = maxima * 50 / 100;
    int idealMax = maxima * 85 / 100;
    cout << "Frequencia cardiaca maxima: " << maxima << " bpm" << endl;
    cout << "Faixa ideal (50%-85% da maxima): "
         << idealMin << " - " << idealMax << " bpm" << endl;
}

double PerfilSaude::obterIMC() const {
    double alturaMetros = alturaCm / 100.0;
    return pesoKg / (alturaMetros * alturaMetros);
}

void PerfilSaude::exibirTabelaIMC() const {
    cout << "\n--- Tabela de classificacao do IMC (OMS) ---" << endl;
    cout << "  Abaixo de 18.5   : Abaixo do peso"        << endl;
    cout << "  18.5 a 24.9      : Peso normal"           << endl;
    cout << "  25.0 a 29.9      : Sobrepeso"             << endl;
    cout << "  30.0 a 34.9      : Obesidade grau I"      << endl;
    cout << "  35.0 a 39.9      : Obesidade grau II"     << endl;
    cout << "  40.0 ou mais     : Obesidade grau III"    << endl;
}

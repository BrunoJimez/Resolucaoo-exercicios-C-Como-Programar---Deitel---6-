// Exercicio 16.16 - FrequenciaCardiaca.cpp
#include <iostream>
#include "FrequenciaCardiaca.h"
using namespace std;

FrequenciaCardiaca::FrequenciaCardiaca(string pn, string sn,
                                       int dn, int mn, int an)
    : primeiroNome(pn), sobrenome(sn),
      diaNascimento(dn), mesNascimento(mn), anoNascimento(an) {
}

void FrequenciaCardiaca::setPrimeiroNome(string n) { primeiroNome = n; }
string FrequenciaCardiaca::getPrimeiroNome() const { return primeiroNome; }

void FrequenciaCardiaca::setSobrenome(string s) { sobrenome = s; }
string FrequenciaCardiaca::getSobrenome() const { return sobrenome; }

void FrequenciaCardiaca::setDiaNascimento(int d) { diaNascimento = d; }
int  FrequenciaCardiaca::getDiaNascimento() const { return diaNascimento; }

void FrequenciaCardiaca::setMesNascimento(int m) { mesNascimento = m; }
int  FrequenciaCardiaca::getMesNascimento() const { return mesNascimento; }

void FrequenciaCardiaca::setAnoNascimento(int a) { anoNascimento = a; }
int  FrequenciaCardiaca::getAnoNascimento() const { return anoNascimento; }

int FrequenciaCardiaca::obterIdade() const {
    int diaAtual, mesAtual, anoAtual;

    cout << "Digite a data atual (dia mes ano): ";
    cin  >> diaAtual >> mesAtual >> anoAtual;

    int idade = anoAtual - anoNascimento;

    // Ajusta caso ainda nao tenha feito aniversario neste ano
    if (mesAtual < mesNascimento ||
        (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        --idade;
    }
    return idade;
}

int FrequenciaCardiaca::obterFrequenciaMaxima() const {
    return 220 - obterIdade();
}

void FrequenciaCardiaca::obterFrequenciaIdeal() const {
    int maxima = obterFrequenciaMaxima();
    int idealMin = maxima * 50 / 100;
    int idealMax = maxima * 85 / 100;

    cout << "Frequencia cardiaca maxima: " << maxima << " bpm" << endl;
    cout << "Faixa ideal (50%-85% da maxima): "
         << idealMin << " - " << idealMax << " bpm" << endl;
}

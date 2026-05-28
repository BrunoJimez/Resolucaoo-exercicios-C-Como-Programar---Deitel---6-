// Exercicio 16.16 - FrequenciaCardiaca.h (Fazendo a Diferenca)
#ifndef FREQUENCIA_CARDIACA_H
#define FREQUENCIA_CARDIACA_H

#include <string>

class FrequenciaCardiaca {
public:
    FrequenciaCardiaca(std::string pnome, std::string snome,
                       int diaNasc, int mesNasc, int anoNasc);

    // Set/get para nome
    void setPrimeiroNome(std::string n);
    std::string getPrimeiroNome() const;

    void setSobrenome(std::string s);
    std::string getSobrenome() const;

    // Set/get para data de nascimento
    void setDiaNascimento(int d);
    int  getDiaNascimento() const;

    void setMesNascimento(int m);
    int  getMesNascimento() const;

    void setAnoNascimento(int a);
    int  getAnoNascimento() const;

    // Calcula idade pedindo data atual ao usuario
    int obterIdade() const;

    // Calcula frequencia cardiaca maxima (220 - idade)
    int obterFrequenciaMaxima() const;

    // Imprime intervalo da frequencia ideal (50% a 85% da maxima)
    void obterFrequenciaIdeal() const;

private:
    std::string primeiroNome;
    std::string sobrenome;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
};

#endif

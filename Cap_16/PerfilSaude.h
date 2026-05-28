// Exercicio 16.17 - PerfilSaude.h (Fazendo a Diferenca)
// Perfil de saude com nome, sexo, data de nascimento, altura e peso
#ifndef PERFIL_SAUDE_H
#define PERFIL_SAUDE_H

#include <string>

class PerfilSaude {
public:
    PerfilSaude(std::string pnome, std::string snome,
                std::string sexo,
                int diaNasc, int mesNasc, int anoNasc,
                int alturaCm, int pesoKg);

    // Setters / getters
    void setPrimeiroNome(std::string n);
    std::string getPrimeiroNome() const;

    void setSobrenome(std::string s);
    std::string getSobrenome() const;

    void setSexo(std::string s);
    std::string getSexo() const;

    void setDiaNascimento(int d);
    int  getDiaNascimento() const;

    void setMesNascimento(int m);
    int  getMesNascimento() const;

    void setAnoNascimento(int a);
    int  getAnoNascimento() const;

    void setAltura(int cm);
    int  getAltura() const;

    void setPeso(int kg);
    int  getPeso() const;

    // Calculos
    int    obterIdade() const;                  // pede data atual
    int    obterFrequenciaMaxima() const;       // 220 - idade
    void   obterFrequenciaIdeal() const;        // 50-85% da maxima
    double obterIMC() const;                    // peso(kg) / altura(m)^2
    void   exibirTabelaIMC() const;             // grafico de faixas

private:
    std::string primeiroNome;
    std::string sobrenome;
    std::string sexo;
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    int alturaCm;     // em centimetros
    int pesoKg;       // em quilogramas
};

#endif

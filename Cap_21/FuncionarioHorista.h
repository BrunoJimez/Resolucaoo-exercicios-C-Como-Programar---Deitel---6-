// Exercicio 21.12 - FuncionarioHorista.h
#ifndef FUNCHORISTA_H
#define FUNCHORISTA_H

#include "Funcionario.h"

class FuncionarioHorista : public Funcionario {
public:
    FuncionarioHorista(const std::string &p, const std::string &s,
                       const std::string &c, const Date &nasc,
                       double salarioPorHora, double horasSemanais);

    void   setSalarioPorHora(double s);   // >= 0
    double getSalarioPorHora() const;
    void   setHoras(double h);            // 0 <= h <= 168 (horas/sem)
    double getHoras() const;

    double earnings() const override;
    void   print()    const override;

private:
    double salarioPorHora;
    double horasSemanais;
};

#endif

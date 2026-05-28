// Exercicio 21.12 - FuncionarioAssalariado.h
#ifndef FUNCASSALARIADO_H
#define FUNCASSALARIADO_H

#include "Funcionario.h"

class FuncionarioAssalariado : public Funcionario {
public:
    FuncionarioAssalariado(const std::string &p, const std::string &s,
                           const std::string &c, const Date &nasc,
                           double salarioSemanal);

    void   setSalarioSemanal(double s);
    double getSalarioSemanal() const;

    // Sobrepoem virtuais (override - palavra-chave do C++11)
    double earnings() const override;
    void   print()    const override;

private:
    double salarioSemanal;
};

#endif

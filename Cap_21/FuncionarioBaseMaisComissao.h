// Exercicio 21.12 - FuncionarioBaseMaisComissao.h
// Herda de FuncionarioComissao e adiciona salario base
#ifndef FUNCBASEMAISCOMISSAO_H
#define FUNCBASEMAISCOMISSAO_H

#include "FuncionarioComissao.h"

class FuncionarioBaseMaisComissao : public FuncionarioComissao {
public:
    FuncionarioBaseMaisComissao(const std::string &p, const std::string &s,
                                const std::string &c, const Date &nasc,
                                double vendasBrutas, double taxaComissao,
                                double salarioBase);

    void   setSalarioBase(double sb);
    double getSalarioBase() const;

    // Redefine: soma salario base aa comissao
    double earnings() const override;
    void   print()    const override;

private:
    double salarioBase;
};

#endif

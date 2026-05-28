// Exercicio 21.12 - FuncionarioComissao.h
#ifndef FUNCCOMISSAO_H
#define FUNCCOMISSAO_H

#include "Funcionario.h"

class FuncionarioComissao : public Funcionario {
public:
    FuncionarioComissao(const std::string &p, const std::string &s,
                        const std::string &c, const Date &nasc,
                        double vendasBrutas, double taxaComissao);

    void   setVendasBrutas(double v);    // >= 0
    double getVendasBrutas() const;
    void   setTaxaComissao(double t);    // 0 < t < 1
    double getTaxaComissao() const;

    double earnings() const override;
    void   print()    const override;

private:
    double vendasBrutas;     // mensal
    double taxaComissao;     // 0 a 1
};

#endif

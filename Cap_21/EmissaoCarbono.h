// Exercicio 21.17 - EmissaoCarbono.h
// Classe abstrata com APENAS funcoes virtuais puras.
// Cada classe que herda deve implementar retEmissaoCarbono().
#ifndef EMISSAOCARBONO_H
#define EMISSAOCARBONO_H

#include <string>

class EmissaoCarbono {
public:
    virtual ~EmissaoCarbono() {}

    // Retorna a emissao anual de CO2 em kg
    virtual double retEmissaoCarbono() const = 0;

    // Para identificacao na impressao
    virtual std::string descricao() const = 0;
};

#endif

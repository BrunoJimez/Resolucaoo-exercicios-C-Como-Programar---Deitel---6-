// Exercicio 21.13 - Forma.h
// Classe-base abstrata para a hierarquia de formas geometricas
#ifndef FORMA_H
#define FORMA_H

#include <string>
#include <iostream>

class Forma {
public:
    Forma(const std::string &nome);
    virtual ~Forma() {}                  // destrutor virtual

    std::string getNome() const;

    // Funcao virtual pura: cada derivada CONCRETA define
    virtual void print() const = 0;

private:
    std::string nome;
};

#endif

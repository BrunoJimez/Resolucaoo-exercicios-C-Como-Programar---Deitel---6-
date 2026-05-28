// Exercicio 21.14 - QuadradoDes.h
#ifndef QUADRADODES_H
#define QUADRADODES_H

#include "FormaDesenhavel.h"

class QuadradoDes : public FormaDesenhavel {
public:
    QuadradoDes(int x, int y, int lado, char p);

    void desenhar(Tela &tela) const override;
    std::string descricao() const override;

private:
    int lado;
};

#endif

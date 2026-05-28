// Exercicio 21.14 - RetanguloDes.h
#ifndef RETANGULODES_H
#define RETANGULODES_H

#include "FormaDesenhavel.h"

class RetanguloDes : public FormaDesenhavel {
public:
    RetanguloDes(int x, int y, int larg, int alt, char p);

    void desenhar(Tela &tela) const override;
    std::string descricao() const override;

private:
    int largura, altura;
};

#endif

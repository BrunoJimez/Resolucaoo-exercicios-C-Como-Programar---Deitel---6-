// Exercicio 21.14 - CirculoDes.h
#ifndef CIRCULODES_H
#define CIRCULODES_H

#include "FormaDesenhavel.h"

class CirculoDes : public FormaDesenhavel {
public:
    // (x, y) e o CENTRO; raio em celulas
    CirculoDes(int x, int y, int raio, char p);

    void desenhar(Tela &tela) const override;
    std::string descricao() const override;

private:
    int raio;
};

#endif

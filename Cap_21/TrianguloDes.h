// Exercicio 21.14 - TrianguloDes.h
// Triangulo retangulo com cateto na origem
#ifndef TRIANGULODES_H
#define TRIANGULODES_H

#include "FormaDesenhavel.h"

class TrianguloDes : public FormaDesenhavel {
public:
    TrianguloDes(int x, int y, int altura, char p);

    void desenhar(Tela &tela) const override;
    std::string descricao() const override;

private:
    int altura;        // tambem = base
};

#endif

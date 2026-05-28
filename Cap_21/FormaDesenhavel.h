// Exercicio 21.14 - FormaDesenhavel.h
// Classe-base abstrata para formas que podem ser desenhadas em ASCII.
// Cada forma tem posicao (x,y), tamanho e caractere de preenchimento.
#ifndef FORMADESENHAVEL_H
#define FORMADESENHAVEL_H

#include <vector>
#include <string>

// Representamos a tela como uma matriz de caracteres
using Tela = std::vector<std::vector<char>>;

class FormaDesenhavel {
public:
    FormaDesenhavel(int x, int y, char preenche);
    virtual ~FormaDesenhavel() {}

    // Funcao virtual pura: cada forma desenha-se na tela
    virtual void desenhar(Tela &tela) const = 0;
    virtual std::string descricao() const = 0;

    int getX() const;
    int getY() const;
    char getPreenchimento() const;

protected:
    int x, y;            // canto de referencia
    char preenche;       // caractere de preenchimento
};

#endif

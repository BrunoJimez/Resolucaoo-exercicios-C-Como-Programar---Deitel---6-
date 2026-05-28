// Exercicio 19.7 - DoubleSubscriptedArray.h
// Array bidimensional com operator() para acesso (linha, coluna)
#ifndef DOUBLESUBSCRIPTED_H
#define DOUBLESUBSCRIPTED_H

#include <iostream>

class DoubleSubscriptedArray {
    friend std::ostream &operator<<(std::ostream &out,
                                    const DoubleSubscriptedArray &a);
    friend std::istream &operator>>(std::istream &in,
                                    DoubleSubscriptedArray &a);
public:
    DoubleSubscriptedArray(int linhas = 3, int colunas = 3);
    DoubleSubscriptedArray(const DoubleSubscriptedArray &outro);
    ~DoubleSubscriptedArray();

    int getLinhas()  const;
    int getColunas() const;

    // operator() para acesso (linha, coluna)
    int       &operator()(int linha, int coluna);
    const int &operator()(int linha, int coluna) const;

    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &o);
    bool operator==(const DoubleSubscriptedArray &o) const;
    bool operator!=(const DoubleSubscriptedArray &o) const;

private:
    int  linhas;
    int  colunas;
    int *dados;   // array LINEAR de linhas*colunas elementos
};

#endif

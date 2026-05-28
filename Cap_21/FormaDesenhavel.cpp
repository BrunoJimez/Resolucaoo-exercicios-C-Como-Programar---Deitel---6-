// Exercicio 21.14 - FormaDesenhavel.cpp
#include "FormaDesenhavel.h"

FormaDesenhavel::FormaDesenhavel(int xi, int yi, char p)
    : x(xi), y(yi), preenche(p) {}

int  FormaDesenhavel::getX() const { return x; }
int  FormaDesenhavel::getY() const { return y; }
char FormaDesenhavel::getPreenchimento() const { return preenche; }

// Exercicio 21.13 - Forma.cpp
#include "Forma.h"
using namespace std;

Forma::Forma(const string &n) : nome(n) {}

string Forma::getNome() const { return nome; }

// Exercicio 19.7 - DoubleSubscriptedArray.cpp
#include <iomanip>
#include <cstdlib>
#include "DoubleSubscriptedArray.h"
using namespace std;

DoubleSubscriptedArray::DoubleSubscriptedArray(int l, int c)
    : linhas(l > 0 ? l : 1), colunas(c > 0 ? c : 1) {
    dados = new int[linhas * colunas];
    for (int i = 0; i < linhas * colunas; ++i) dados[i] = 0;
}

DoubleSubscriptedArray::DoubleSubscriptedArray(
        const DoubleSubscriptedArray &o)
    : linhas(o.linhas), colunas(o.colunas) {
    dados = new int[linhas * colunas];
    for (int i = 0; i < linhas * colunas; ++i) dados[i] = o.dados[i];
}

DoubleSubscriptedArray::~DoubleSubscriptedArray() {
    delete[] dados;
}

int DoubleSubscriptedArray::getLinhas()  const { return linhas; }
int DoubleSubscriptedArray::getColunas() const { return colunas; }

// Versao nao-const: retorna referencia mutavel (lvalue)
int &DoubleSubscriptedArray::operator()(int linha, int coluna) {
    if (linha < 0 || linha >= linhas
        || coluna < 0 || coluna >= colunas) {
        cerr << "Indice fora dos limites." << endl;
        exit(1);
    }
    return dados[linha * colunas + coluna];
}

// Versao const: para objetos const, retorna referencia const
const int &DoubleSubscriptedArray::operator()(int linha, int coluna) const {
    if (linha < 0 || linha >= linhas
        || coluna < 0 || coluna >= colunas) {
        cerr << "Indice fora dos limites." << endl;
        exit(1);
    }
    return dados[linha * colunas + coluna];
}

const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(
        const DoubleSubscriptedArray &o) {
    if (this != &o) {                   // protecao contra autoatribuicao
        if (linhas != o.linhas || colunas != o.colunas) {
            delete[] dados;
            linhas  = o.linhas;
            colunas = o.colunas;
            dados   = new int[linhas * colunas];
        }
        for (int i = 0; i < linhas * colunas; ++i) dados[i] = o.dados[i];
    }
    return *this;
}

bool DoubleSubscriptedArray::operator==(
        const DoubleSubscriptedArray &o) const {
    if (linhas != o.linhas || colunas != o.colunas) return false;
    for (int i = 0; i < linhas * colunas; ++i)
        if (dados[i] != o.dados[i]) return false;
    return true;
}

bool DoubleSubscriptedArray::operator!=(
        const DoubleSubscriptedArray &o) const {
    return !(*this == o);
}

// Operador de extracao: le todos os elementos do array
istream &operator>>(istream &in, DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.linhas * a.colunas; ++i) in >> a.dados[i];
    return in;
}

// Operador de insercao: imprime em formato de matriz
ostream &operator<<(ostream &out, const DoubleSubscriptedArray &a) {
    for (int i = 0; i < a.linhas; ++i) {
        for (int j = 0; j < a.colunas; ++j) {
            out << setw(6) << a.dados[i * a.colunas + j];
        }
        out << endl;
    }
    return out;
}

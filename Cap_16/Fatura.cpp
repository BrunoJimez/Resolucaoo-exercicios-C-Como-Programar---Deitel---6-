// Exercicio 16.13 - Fatura.cpp
#include "Fatura.h"
using namespace std;

Fatura::Fatura(string np, string desc, int qtd, int preco)
    : numeroPeca(np), descricao(desc) {
    setQuantidade(qtd);     // usa o setter para validar
    setPrecoPorItem(preco); // usa o setter para validar
}

void Fatura::setNumeroPeca(string n) { numeroPeca = n; }
string Fatura::getNumeroPeca() const { return numeroPeca; }

void Fatura::setDescricao(string d) { descricao = d; }
string Fatura::getDescricao() const { return descricao; }

void Fatura::setQuantidade(int q) {
    quantidade = (q > 0) ? q : 0;   // se nao positiva, define 0
}
int Fatura::getQuantidade() const { return quantidade; }

void Fatura::setPrecoPorItem(int p) {
    precoPorItem = (p > 0) ? p : 0; // se nao positivo, define 0
}
int Fatura::getPrecoPorItem() const { return precoPorItem; }

int Fatura::obterValorFatura() const {
    return quantidade * precoPorItem;
}

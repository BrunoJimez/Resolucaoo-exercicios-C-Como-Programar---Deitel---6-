// Exercicio 19.11 - Polynomial.cpp
#include <algorithm>
#include <cmath>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial() : termos(nullptr), qtd(0) {}

Polynomial::Polynomial(const Termo *t, int n) : qtd(n) {
    termos = new Termo[qtd];
    for (int i = 0; i < qtd; ++i) termos[i] = t[i];
    normalizar();
}

Polynomial::Polynomial(const Polynomial &o) : qtd(o.qtd) {
    termos = new Termo[qtd];
    for (int i = 0; i < qtd; ++i) termos[i] = o.termos[i];
}

Polynomial::~Polynomial() {
    delete[] termos;
}

int    Polynomial::getNumeroDeTermos() const { return qtd; }
double Polynomial::getCoeficiente(int i) const { return termos[i].coeficiente; }
int    Polynomial::getExpoente(int i)    const { return termos[i].expoente; }

// Insere/atualiza um termo: se ja existe um termo com o mesmo expoente,
// substitui o coeficiente; senao, adiciona
void Polynomial::setTermo(int expoente, double coeficiente) {
    for (int i = 0; i < qtd; ++i) {
        if (termos[i].expoente == expoente) {
            termos[i].coeficiente = coeficiente;
            normalizar();
            return;
        }
    }
    // Nao existe -> cria espaco maior e adiciona
    Termo *novo = new Termo[qtd + 1];
    for (int i = 0; i < qtd; ++i) novo[i] = termos[i];
    novo[qtd].expoente    = expoente;
    novo[qtd].coeficiente = coeficiente;
    delete[] termos;
    termos = novo;
    ++qtd;
    normalizar();
}

// Remove termos com coeficiente 0 e ordena por expoente decrescente
void Polynomial::normalizar() {
    // Remove zeros (em um polinomio temporariamente "sujo")
    int j = 0;
    for (int i = 0; i < qtd; ++i)
        if (termos[i].coeficiente != 0.0)
            termos[j++] = termos[i];
    qtd = j;
    // Ordena por expoente decrescente
    sort(termos, termos + qtd, [](const Termo &a, const Termo &b) {
        return a.expoente > b.expoente;
    });
}

Polynomial Polynomial::operator+(const Polynomial &o) const {
    Polynomial r;
    // Reserva tamanho maximo
    r.termos = new Termo[qtd + o.qtd];
    r.qtd = 0;
    // Copia todos os termos de *this
    for (int i = 0; i < qtd; ++i) r.termos[r.qtd++] = termos[i];
    // Adiciona ou soma de o
    for (int i = 0; i < o.qtd; ++i) {
        bool achou = false;
        for (int k = 0; k < r.qtd; ++k) {
            if (r.termos[k].expoente == o.termos[i].expoente) {
                r.termos[k].coeficiente += o.termos[i].coeficiente;
                achou = true;
                break;
            }
        }
        if (!achou) r.termos[r.qtd++] = o.termos[i];
    }
    r.normalizar();
    return r;
}

Polynomial Polynomial::operator-(const Polynomial &o) const {
    Polynomial neg(o);   // copia o
    for (int i = 0; i < neg.qtd; ++i) neg.termos[i].coeficiente *= -1;
    return *this + neg;
}

Polynomial Polynomial::operator*(const Polynomial &o) const {
    Polynomial r;
    r.termos = new Termo[qtd * o.qtd];
    r.qtd = 0;
    for (int i = 0; i < qtd; ++i) {
        for (int j = 0; j < o.qtd; ++j) {
            int expProd = termos[i].expoente + o.termos[j].expoente;
            double cProd = termos[i].coeficiente * o.termos[j].coeficiente;
            // Verifica se ja temos esse expoente
            bool achou = false;
            for (int k = 0; k < r.qtd; ++k) {
                if (r.termos[k].expoente == expProd) {
                    r.termos[k].coeficiente += cProd;
                    achou = true; break;
                }
            }
            if (!achou) {
                r.termos[r.qtd].expoente    = expProd;
                r.termos[r.qtd].coeficiente = cProd;
                ++r.qtd;
            }
        }
    }
    r.normalizar();
    return r;
}

const Polynomial &Polynomial::operator=(const Polynomial &o) {
    if (this != &o) {
        delete[] termos;
        qtd = o.qtd;
        termos = new Termo[qtd];
        for (int i = 0; i < qtd; ++i) termos[i] = o.termos[i];
    }
    return *this;
}

const Polynomial &Polynomial::operator+=(const Polynomial &o) {
    *this = *this + o;
    return *this;
}

const Polynomial &Polynomial::operator-=(const Polynomial &o) {
    *this = *this - o;
    return *this;
}

const Polynomial &Polynomial::operator*=(const Polynomial &o) {
    *this = *this * o;
    return *this;
}

// Impressao em formato canonico: 3x^2 + 2x - 5
ostream &operator<<(ostream &out, const Polynomial &p) {
    if (p.qtd == 0) { out << "0"; return out; }
    for (int i = 0; i < p.qtd; ++i) {
        double c = p.termos[i].coeficiente;
        int    e = p.termos[i].expoente;

        // Sinal
        if (i == 0) {
            if (c < 0) out << "-";
        } else {
            out << (c >= 0 ? " + " : " - ");
        }
        double cAbs = std::fabs(c);

        // Coeficiente (omite se for 1 e o expoente nao for 0)
        if (cAbs != 1.0 || e == 0) out << cAbs;

        // Variavel e expoente
        if (e == 0) {
            ;
        } else if (e == 1) {
            out << "x";
        } else {
            out << "x^" << e;
        }
    }
    return out;
}

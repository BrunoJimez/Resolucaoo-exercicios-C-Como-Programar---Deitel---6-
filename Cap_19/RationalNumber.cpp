// Exercicio 19.10 - RationalNumber.cpp
#include <cstdlib>
#include "RationalNumber.h"
using namespace std;

RationalNumber::RationalNumber(int numerador, int denominador)
    : num(numerador), den(denominador) {
    if (den == 0) {
        cerr << "Erro: denominador 0. Ajustado para 1." << endl;
        den = 1;
    }
    if (den < 0) { num = -num; den = -den; }  // sinal sempre no numerador
    reduzir();
}

int RationalNumber::mdc(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) { int t = b; b = a % b; a = t; }
    return a == 0 ? 1 : a;
}

void RationalNumber::reduzir() {
    int d = mdc(num, den);
    num /= d;
    den /= d;
}

RationalNumber RationalNumber::operator+(const RationalNumber &o) const {
    return RationalNumber(num * o.den + o.num * den, den * o.den);
}

RationalNumber RationalNumber::operator-(const RationalNumber &o) const {
    return RationalNumber(num * o.den - o.num * den, den * o.den);
}

RationalNumber RationalNumber::operator*(const RationalNumber &o) const {
    return RationalNumber(num * o.num, den * o.den);
}

RationalNumber RationalNumber::operator/(const RationalNumber &o) const {
    return RationalNumber(num * o.den, den * o.num);
}

// Para comparar a/b ?= c/d, evitamos divisao em ponto flutuante:
// compara a*d com c*b (lembrar que ambos den > 0)
bool RationalNumber::operator==(const RationalNumber &o) const {
    return num == o.num && den == o.den;     // ambos ja reduzidos!
}
bool RationalNumber::operator!=(const RationalNumber &o) const {
    return !(*this == o);
}
bool RationalNumber::operator<(const RationalNumber &o) const {
    return num * o.den < o.num * den;
}
bool RationalNumber::operator>(const RationalNumber &o) const { return o < *this; }
bool RationalNumber::operator<=(const RationalNumber &o) const { return !(*this > o); }
bool RationalNumber::operator>=(const RationalNumber &o) const { return !(*this < o); }

// I/O
ostream &operator<<(ostream &out, const RationalNumber &r) {
    if (r.den == 1) out << r.num;
    else            out << r.num << "/" << r.den;
    return out;
}

// Le no formato "num / den" ou "num"
istream &operator>>(istream &in, RationalNumber &r) {
    int n, d = 1;
    in >> n;
    if (in.peek() == '/') {
        in.get();          // descarta '/'
        in >> d;
    }
    r = RationalNumber(n, d);
    return in;
}

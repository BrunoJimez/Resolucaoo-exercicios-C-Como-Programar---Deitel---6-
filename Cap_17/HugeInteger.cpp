// Exercicio 17.14 - HugeInteger.cpp
#include <iostream>
#include <string>
#include <cctype>
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger() {
    for (int i = 0; i < TAMANHO; ++i) digitos[i] = 0;
}

HugeInteger::HugeInteger(const string &s) {
    for (int i = 0; i < TAMANHO; ++i) digitos[i] = 0;
    // Le caracteres da string da direita para a esquerda
    int idx = 0;
    for (int i = static_cast<int>(s.length()) - 1; i >= 0 && idx < TAMANHO; --i) {
        if (isdigit(static_cast<unsigned char>(s[i]))) {
            digitos[idx++] = s[i] - '0';
        }
    }
}

void HugeInteger::input() {
    string s;
    cout << "Digite um inteiro grande (ate 40 digitos): ";
    cin >> s;
    *this = HugeInteger(s);
}

void HugeInteger::output() const {
    // Acha o digito mais a esquerda nao-zero
    int i = TAMANHO - 1;
    while (i > 0 && digitos[i] == 0) --i;
    for (; i >= 0; --i) cout << digitos[i];
}

HugeInteger HugeInteger::add(const HugeInteger &o) const {
    HugeInteger r;
    int carry = 0;
    for (int i = 0; i < TAMANHO; ++i) {
        int s = digitos[i] + o.digitos[i] + carry;
        r.digitos[i] = s % 10;
        carry = s / 10;
    }
    // Carry final descartado se ultrapassar 40 digitos
    return r;
}

HugeInteger HugeInteger::subtract(const HugeInteger &o) const {
    // Subtracao simples: assume *this >= o; resultado nao-negativo
    HugeInteger r;
    int borrow = 0;
    for (int i = 0; i < TAMANHO; ++i) {
        int d = digitos[i] - o.digitos[i] - borrow;
        if (d < 0) { d += 10; borrow = 1; }
        else       { borrow = 0; }
        r.digitos[i] = d;
    }
    return r;
}

bool HugeInteger::isEqualTo(const HugeInteger &o) const {
    for (int i = 0; i < TAMANHO; ++i)
        if (digitos[i] != o.digitos[i]) return false;
    return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &o) const {
    return !isEqualTo(o);
}

bool HugeInteger::isGreaterThan(const HugeInteger &o) const {
    for (int i = TAMANHO - 1; i >= 0; --i) {
        if (digitos[i] > o.digitos[i]) return true;
        if (digitos[i] < o.digitos[i]) return false;
    }
    return false;   // iguais
}

bool HugeInteger::isLessThan(const HugeInteger &o) const {
    return o.isGreaterThan(*this);
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger &o) const {
    return !isLessThan(o);
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger &o) const {
    return !isGreaterThan(o);
}

bool HugeInteger::isZero() const {
    for (int i = 0; i < TAMANHO; ++i)
        if (digitos[i] != 0) return false;
    return true;
}

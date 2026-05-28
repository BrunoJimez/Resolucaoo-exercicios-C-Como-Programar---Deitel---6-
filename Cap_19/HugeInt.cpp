// Exercicio 19.9 - HugeInt.cpp
#include <cctype>
#include "HugeInt.h"
using namespace std;

HugeInt::HugeInt(long value) {
    for (int i = 0; i < digits; ++i) integer[i] = 0;
    for (int j = digits - 1; value != 0 && j >= 0; --j) {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const string &number) {
    for (int i = 0; i < digits; ++i) integer[i] = 0;
    int length = static_cast<int>(number.size());
    for (int j = digits - length, k = 0; j < digits; ++j, ++k) {
        if (isdigit(static_cast<unsigned char>(number[k])))
            integer[j] = number[k] - '0';
    }
}

HugeInt HugeInt::operator+(const HugeInt &op2) const {
    HugeInt temp;
    int carry = 0;
    for (int i = digits - 1; i >= 0; --i) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) { temp.integer[i] %= 10; carry = 1; }
        else                       carry = 0;
    }
    return temp;
}

HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const string &op2) const {
    return *this + HugeInt(op2);
}

// Subtracao: assume *this >= op2 (resultado nao-negativo)
HugeInt HugeInt::operator-(const HugeInt &op2) const {
    HugeInt temp;
    int borrow = 0;
    for (int i = digits - 1; i >= 0; --i) {
        int d = integer[i] - op2.integer[i] - borrow;
        if (d < 0) { d += 10; borrow = 1; }
        else         borrow = 0;
        temp.integer[i] = d;
    }
    return temp;
}

// (c) Multiplicacao: O(digits^2) - estilo escolar
HugeInt HugeInt::operator*(const HugeInt &op2) const {
    HugeInt temp;
    for (int i = digits - 1; i >= 0; --i) {        // digito de *this
        if (integer[i] == 0) continue;
        int carry = 0;
        for (int j = digits - 1; j >= 0; --j) {     // digito de op2
            int posicao = i + j - (digits - 1);     // posicao no resultado
            if (posicao < 0) {
                // ultrapassa o tamanho - ignora (overflow)
                if (integer[i] * op2.integer[j] + carry != 0) {
                    // overflow silencioso
                }
                continue;
            }
            int s = temp.integer[posicao]
                    + integer[i] * op2.integer[j] + carry;
            temp.integer[posicao] = s % 10;
            carry = s / 10;
        }
    }
    return temp;
}

// (d) Divisao: por subtracoes repetidas (simples mas ineficiente)
HugeInt HugeInt::operator/(const HugeInt &op2) const {
    HugeInt quociente;
    if (op2.isZero()) return quociente;            // divisao por zero -> 0
    HugeInt resto = *this;
    while (resto >= op2) {
        resto = resto - op2;
        quociente = quociente + HugeInt(1L);
    }
    return quociente;
}

bool HugeInt::isZero() const {
    for (int i = 0; i < digits; ++i)
        if (integer[i] != 0) return false;
    return true;
}

// (e) Relacionais
bool HugeInt::operator==(const HugeInt &o) const {
    for (int i = 0; i < digits; ++i)
        if (integer[i] != o.integer[i]) return false;
    return true;
}

bool HugeInt::operator!=(const HugeInt &o) const { return !(*this == o); }

bool HugeInt::operator>(const HugeInt &o) const {
    for (int i = 0; i < digits; ++i) {
        if (integer[i] > o.integer[i]) return true;
        if (integer[i] < o.integer[i]) return false;
    }
    return false;
}

bool HugeInt::operator<(const HugeInt &o) const  { return o > *this; }
bool HugeInt::operator>=(const HugeInt &o) const { return !(*this < o); }
bool HugeInt::operator<=(const HugeInt &o) const { return !(*this > o); }

ostream &operator<<(ostream &output, const HugeInt &num) {
    int i;
    for (i = 0; num.integer[i] == 0 && i <= HugeInt::digits; ++i)
        ;       // pula zeros a esquerda
    if (i == HugeInt::digits) output << 0;
    else for (; i < HugeInt::digits; ++i) output << num.integer[i];
    return output;
}

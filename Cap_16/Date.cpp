// Exercicio 16.15 - Date.cpp
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int a)
    : dia(d), ano(a) {
    setMes(m);   // valida o mes via setter
}

void Date::setMes(int m) {
    if (m >= 1 && m <= 12) {
        mes = m;
    } else {
        cout << "Mes invalido (" << m << "). Definido como 1." << endl;
        mes = 1;
    }
}
int Date::getMes() const { return mes; }

void Date::setDia(int d) { dia = d; }
int  Date::getDia() const { return dia; }

void Date::setAno(int a) { ano = a; }
int  Date::getAno() const { return ano; }

void Date::mostraData() const {
    cout << mes << "/" << dia << "/" << ano << endl;
}

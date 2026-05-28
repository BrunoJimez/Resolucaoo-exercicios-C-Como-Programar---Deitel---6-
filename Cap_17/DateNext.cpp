// Exercicio 17.8 - DateNext.cpp
#include <iostream>
#include "DateNext.h"
using namespace std;

DateNext::DateNext(int m, int d, int y) {
    setYear(y);
    setMonth(m);
    setDay(d);
}

bool DateNext::ehBissexto(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateNext::diasDoMes() const {
    static const int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && ehBissexto(year)) return 29;
    return dias[month - 1];
}

void DateNext::setMonth(int m) {
    if (m >= 1 && m <= 12) month = m;
    else {
        cout << "Mes invalido (" << m << "). Definido como 1." << endl;
        month = 1;
    }
}

void DateNext::setDay(int d) {
    int max = diasDoMes();
    if (d >= 1 && d <= max) day = d;
    else {
        cout << "Dia invalido (" << d << ") para mes " << month
             << "/" << year << ". Definido como 1." << endl;
        day = 1;
    }
}

void DateNext::setYear(int y) {
    if (y >= 1) year = y;
    else {
        cout << "Ano invalido (" << y << "). Definido como 2000." << endl;
        year = 2000;
    }
}

int DateNext::getMonth() const { return month; }
int DateNext::getDay()   const { return day;   }
int DateNext::getYear()  const { return year;  }

void DateNext::nextDay() {
    ++day;
    if (day > diasDoMes()) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}

void DateNext::print() const {
    cout << month << "/" << day << "/" << year;
}

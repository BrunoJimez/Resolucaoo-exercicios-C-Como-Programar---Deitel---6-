// Exercicio 17.9 - DateAndTime.cpp
#include <iostream>
#include <iomanip>
#include "DateAndTime.h"
using namespace std;

DateAndTime::DateAndTime(int mes, int dia, int ano, int h, int m, int s) {
    setDate(mes, dia, ano);
    setTime(h, m, s);
}

bool DateAndTime::ehBissexto(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateAndTime::diasDoMes() const {
    static const int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && ehBissexto(year)) return 29;
    return dias[month - 1];
}

void DateAndTime::setTime(int h, int m, int s) {
    hour   = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

int DateAndTime::getHour()   const { return hour;   }
int DateAndTime::getMinute() const { return minute; }
int DateAndTime::getSecond() const { return second; }

void DateAndTime::setDate(int mes, int dia, int ano) {
    year  = (ano >= 1) ? ano : 2000;
    month = (mes >= 1 && mes <= 12) ? mes : 1;
    day   = (dia >= 1 && dia <= diasDoMes()) ? dia : 1;
}

int DateAndTime::getMonth() const { return month; }
int DateAndTime::getDay()   const { return day;   }
int DateAndTime::getYear()  const { return year;  }

void DateAndTime::nextDay() {
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

void DateAndTime::tick() {
    ++second;
    if (second == 60) {
        second = 0;
        ++minute;
        if (minute == 60) {
            minute = 0;
            ++hour;
            if (hour == 24) {
                hour = 0;
                nextDay();    // delega para nextDay
            }
        }
    }
}

void DateAndTime::printUniversal() const {
    cout << month << "/" << day << "/" << year << " "
         << setfill('0')
         << setw(2) << hour   << ':'
         << setw(2) << minute << ':'
         << setw(2) << second
         << setfill(' ');
}

void DateAndTime::printStandard() const {
    int h12 = ((hour == 0 || hour == 12) ? 12 : hour % 12);
    cout << month << "/" << day << "/" << year << " "
         << setfill('0')
         << setw(2) << h12    << ':'
         << setw(2) << minute << ':'
         << setw(2) << second
         << (hour < 12 ? " AM" : " PM")
         << setfill(' ');
}

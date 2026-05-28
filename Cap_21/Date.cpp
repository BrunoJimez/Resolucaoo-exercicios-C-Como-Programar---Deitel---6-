// Date.cpp
#include "Date.h"
using namespace std;

bool Date::ehBissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int Date::diasDoMes(int m, int a) {
    static const int dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m < 1 || m > 12) return 31;
    if (m == 2 && ehBissexto(a)) return 29;
    return dias[m - 1];
}

Date::Date(int m, int d, int a) {
    ano = (a >= 1) ? a : 2000;
    mes = (m >= 1 && m <= 12) ? m : 1;
    int maxDia = diasDoMes(mes, ano);
    dia = (d >= 1 && d <= maxDia) ? d : 1;
}

int Date::getMes() const { return mes; }
int Date::getDia() const { return dia; }
int Date::getAno() const { return ano; }

ostream &operator<<(ostream &out, const Date &d) {
    out << d.dia << "/" << d.mes << "/" << d.ano;
    return out;
}

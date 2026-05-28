// Date.h - reaproveitado do Cap. 18 (simplificado)
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

class Date {
    friend std::ostream &operator<<(std::ostream &out, const Date &d);
public:
    Date(int mes = 1, int dia = 1, int ano = 2000);

    int getMes() const;
    int getDia() const;
    int getAno() const;

private:
    int mes, dia, ano;

    static bool ehBissexto(int a);
    static int  diasDoMes(int m, int a);
};

#endif

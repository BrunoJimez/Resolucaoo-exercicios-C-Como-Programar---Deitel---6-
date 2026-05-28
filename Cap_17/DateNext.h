// Exercicio 17.8 - DateNext.h
// Classe Date com verificacao de erro e funcao nextDay
#ifndef DATENEXT_H
#define DATENEXT_H

class DateNext {
public:
    DateNext(int m = 1, int d = 1, int y = 2000);

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);
    int  getMonth() const;
    int  getDay() const;
    int  getYear() const;

    // Avanca a data em um dia, propagando para mes/ano
    void nextDay();
    void print() const;     // formato mm/dd/yyyy

private:
    int month;
    int day;
    int year;

    // Quantos dias tem este mes (considerando ano bissexto)
    int diasDoMes() const;
    static bool ehBissexto(int y);
};

#endif

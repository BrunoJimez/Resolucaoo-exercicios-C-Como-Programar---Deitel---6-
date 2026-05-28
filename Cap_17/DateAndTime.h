// Exercicio 17.9 - DateAndTime.h
// Combina Date e Time em uma unica classe; tick chama nextDay quando passa de 23:59:59
#ifndef DATEANDTIME_H
#define DATEANDTIME_H

class DateAndTime {
public:
    DateAndTime(int mes = 1, int dia = 1, int ano = 2000,
                int h = 0, int m = 0, int s = 0);

    // Time
    void setTime(int h, int m, int s);
    int  getHour() const;
    int  getMinute() const;
    int  getSecond() const;

    // Date
    void setDate(int mes, int dia, int ano);
    int  getMonth() const;
    int  getDay() const;
    int  getYear() const;

    // Tick e nextDay
    void tick();        // incrementa 1 segundo; chama nextDay no fim do dia
    void nextDay();     // avanca 1 dia, propagando mes/ano

    void printStandard() const;
    void printUniversal() const;

private:
    int hour, minute, second;
    int month, day, year;

    int  diasDoMes() const;
    static bool ehBissexto(int y);
};

#endif

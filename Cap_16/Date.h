// Exercicio 16.15 - Date.h
#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date(int mes, int dia, int ano);

    // setters / getters
    void setMes(int m);
    int  getMes() const;

    void setDia(int d);
    int  getDia() const;

    void setAno(int a);
    int  getAno() const;

    // Exibe a data no formato mes/dia/ano
    void mostraData() const;

private:
    int mes;
    int dia;
    int ano;
};

#endif

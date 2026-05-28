// Exercicio 16.13 - Fatura.h
// Declaracao da classe Fatura
#ifndef FATURA_H
#define FATURA_H

#include <string>

class Fatura {
public:
    // Construtor inicializa os quatro dados-membro
    Fatura(std::string numeroPeca, std::string descricao,
           int quantidade, int precoPorItem);

    // Set/get para o numero da peca
    void setNumeroPeca(std::string n);
    std::string getNumeroPeca() const;

    // Set/get para a descricao
    void setDescricao(std::string d);
    std::string getDescricao() const;

    // Set/get para a quantidade (validada)
    void setQuantidade(int q);
    int getQuantidade() const;

    // Set/get para o preco por item (validado)
    void setPrecoPorItem(int p);
    int getPrecoPorItem() const;

    // Calcula e retorna o valor total da fatura
    int obterValorFatura() const;

private:
    std::string numeroPeca;
    std::string descricao;
    int quantidade;
    int precoPorItem;
};

#endif

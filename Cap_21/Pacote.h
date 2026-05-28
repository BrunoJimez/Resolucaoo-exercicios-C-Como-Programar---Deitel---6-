// Exercicio 21.15 - Pacote.h
// Igual ao do Cap. 20, mas agora com virtual em calculaCusto()
// e novos getters para enderecos do remetente e destinatario
#ifndef PACOTE_H
#define PACOTE_H

#include <string>

class Pacote {
public:
    Pacote(const std::string &nomeRem, const std::string &endRem,
           const std::string &cidadeRem, const std::string &estadoRem,
           const std::string &cepRem,
           const std::string &nomeDest, const std::string &endDest,
           const std::string &cidadeDest, const std::string &estadoDest,
           const std::string &cepDest,
           double pesoG, double custoPorG);

    virtual ~Pacote() {}      // destrutor virtual

    void setPeso(double p);
    double getPeso() const;
    void setCustoPorGrama(double c);
    double getCustoPorGrama() const;

    // === FUNCAO VIRTUAL ===
    virtual double calculaCusto() const;

    // Getters para a etiqueta polimorfica do 21.15
    std::string getNomeRemetente() const;
    std::string getEnderecoRemetente() const;
    std::string getCidadeRemetente() const;
    std::string getEstadoRemetente() const;
    std::string getCepRemetente() const;
    std::string getNomeDestinatario() const;
    std::string getEnderecoDestinatario() const;
    std::string getCidadeDestinatario() const;
    std::string getEstadoDestinatario() const;
    std::string getCepDestinatario() const;

protected:
    double peso;
    double custoPorGrama;

private:
    std::string nomeRemetente,    enderecoRemetente;
    std::string cidadeRemetente,  estadoRemetente, cepRemetente;
    std::string nomeDestinatario, enderecoDestinatario;
    std::string cidadeDestinatario, estadoDestinatario, cepDestinatario;
};

#endif

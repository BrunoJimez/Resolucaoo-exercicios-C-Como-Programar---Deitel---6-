// Exercicio 21.15 - Pacote.cpp
#include "Pacote.h"
using namespace std;

Pacote::Pacote(const string &nR, const string &eR,
               const string &cR, const string &esR, const string &cepR,
               const string &nD, const string &eD,
               const string &cD, const string &esD, const string &cepD,
               double p, double c)
    : nomeRemetente(nR), enderecoRemetente(eR),
      cidadeRemetente(cR), estadoRemetente(esR), cepRemetente(cepR),
      nomeDestinatario(nD), enderecoDestinatario(eD),
      cidadeDestinatario(cD), estadoDestinatario(esD), cepDestinatario(cepD) {
    setPeso(p);
    setCustoPorGrama(c);
}

void Pacote::setPeso(double p) { peso = (p >= 0) ? p : 0; }
double Pacote::getPeso() const { return peso; }
void Pacote::setCustoPorGrama(double c) { custoPorGrama = (c >= 0) ? c : 0; }
double Pacote::getCustoPorGrama() const { return custoPorGrama; }

double Pacote::calculaCusto() const { return peso * custoPorGrama; }

string Pacote::getNomeRemetente()       const { return nomeRemetente; }
string Pacote::getEnderecoRemetente()   const { return enderecoRemetente; }
string Pacote::getCidadeRemetente()     const { return cidadeRemetente; }
string Pacote::getEstadoRemetente()     const { return estadoRemetente; }
string Pacote::getCepRemetente()        const { return cepRemetente; }
string Pacote::getNomeDestinatario()    const { return nomeDestinatario; }
string Pacote::getEnderecoDestinatario()const { return enderecoDestinatario; }
string Pacote::getCidadeDestinatario()  const { return cidadeDestinatario; }
string Pacote::getEstadoDestinatario()  const { return estadoDestinatario; }
string Pacote::getCepDestinatario()     const { return cepDestinatario; }

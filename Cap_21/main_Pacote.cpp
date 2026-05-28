// Exercicio 21.15 - main_Pacote.cpp
// Processa um vector<Pacote*> polimorficamente: imprime etiquetas
// e acumula o custo total de envio.
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Pacote.h"
#include "PacoteDoisDias.h"
#include "PacoteNoturno.h"
using namespace std;

// Imprime uma "etiqueta" como apareceria no envelope
void imprimirEtiqueta(const Pacote &p) {
    cout << "+----------------------------------------+\n";
    cout << "| DE:  " << p.getNomeRemetente() << "\n";
    cout << "|      " << p.getEnderecoRemetente() << "\n";
    cout << "|      " << p.getCidadeRemetente() << "-"
         << p.getEstadoRemetente() << "  " << p.getCepRemetente() << "\n";
    cout << "|----------------------------------------|\n";
    cout << "| PARA: " << p.getNomeDestinatario() << "\n";
    cout << "|       " << p.getEnderecoDestinatario() << "\n";
    cout << "|       " << p.getCidadeDestinatario() << "-"
         << p.getEstadoDestinatario() << "  "
         << p.getCepDestinatario() << "\n";
    cout << "+----------------------------------------+\n";
}

int main() {
    cout << fixed << setprecision(2);

    vector<unique_ptr<Pacote>> remessas;
    remessas.push_back(unique_ptr<Pacote>(new Pacote(
        "Maria Souza", "Rua A, 100", "Sao Paulo", "SP", "01000-000",
        "Joao Silva", "Av. B, 250", "Rio de Janeiro", "RJ", "20000-000",
        1500.0, 0.02)));
    remessas.push_back(unique_ptr<Pacote>(new PacoteDoisDias(
        "Ana Costa", "Rua C, 5", "Belo Horizonte", "MG", "30000-000",
        "Pedro Lima", "Av. D, 8", "Salvador", "BA", "40000-000",
        2000.0, 0.025, 15.00)));
    remessas.push_back(unique_ptr<Pacote>(new PacoteNoturno(
        "Carlos Mendes", "Rua E, 12", "Recife", "PE", "50000-000",
        "Lucia Pereira", "Av. F, 20", "Curitiba", "PR", "80000-000",
        500.0, 0.03, 0.01)));

    double totalEnvio = 0;
    int i = 1;
    for (const auto &p : remessas) {
        cout << "\n>>> REMESSA " << i++ << " <<<\n";
        imprimirEtiqueta(*p);
        double custo = p->calculaCusto();    // POLIMORFISMO!
        cout << "Custo de envio: R$ " << custo << "\n";
        totalEnvio += custo;
    }

    cout << "\n========================================\n";
    cout << "TOTAL DE TODAS AS REMESSAS: R$ " << totalEnvio << "\n";
    cout << "========================================\n";
    return 0;
}

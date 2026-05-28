// Exercicio 21.17 - main_EmissaoCarbono.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "EmissaoCarbono.h"
#include "Predio.h"
#include "Carro.h"
#include "Bicicleta.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);

    vector<unique_ptr<EmissaoCarbono>> objetos;
    objetos.push_back(unique_ptr<EmissaoCarbono>(
        new Predio("Av. Paulista, 1000 - Sao Paulo", 50000)));
    objetos.push_back(unique_ptr<EmissaoCarbono>(
        new Predio("Rua Augusta, 200 - Sao Paulo", 12000)));
    objetos.push_back(unique_ptr<EmissaoCarbono>(
        new Carro("Honda Civic 1.5", 15000, 12)));
    objetos.push_back(unique_ptr<EmissaoCarbono>(
        new Carro("Toyota Hilux 2.8", 20000, 8)));
    objetos.push_back(unique_ptr<EmissaoCarbono>(
        new Bicicleta("Caloi 10", 15)));

    cout << "=== Relatorio de Emissao de Carbono ===\n\n";

    double total = 0;
    for (const auto &obj : objetos) {
        double e = obj->retEmissaoCarbono();   // POLIMORFICO!
        cout << obj->descricao() << "\n"
             << "  -> " << e << " kg CO2/ano\n\n";
        total += e;
    }

    cout << "========================================\n";
    cout << "TOTAL DE EMISSOES: " << total << " kg CO2/ano\n";
    cout << "                 = " << (total / 1000) << " toneladas CO2/ano\n";
    cout << "========================================\n";
    return 0;
}

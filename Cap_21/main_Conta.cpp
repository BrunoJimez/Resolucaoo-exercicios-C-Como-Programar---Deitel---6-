// Exercicio 21.16 - main_Conta.cpp
// Processa um vector<Conta*> polimorficamente.
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "Conta.h"
#include "ContaPoupanca.h"
#include "ContaCorrente.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);

    vector<unique_ptr<Conta>> contas;
    contas.push_back(unique_ptr<Conta>(new ContaPoupanca(2000.00, 0.03)));
    contas.push_back(unique_ptr<Conta>(new ContaCorrente(1000.00, 2.00)));
    contas.push_back(unique_ptr<Conta>(new ContaPoupanca(5000.00, 0.05)));

    // Cenario pre-roteirizado: cada conta recebe um deposito e um saque
    struct Operacao { double deposito; double saque; };
    Operacao ops[] = { {500, 100}, {200, 300}, {1000, 500} };

    cout << "=== Processamento polimorfico de contas ===\n";
    for (size_t i = 0; i < contas.size(); ++i) {
        Conta &c = *contas[i];
        cout << "\n--- Conta " << (i + 1) << " ---\n";
        cout << "Saldo inicial: R$ " << c.retSaldo() << "\n";

        c.creditar(ops[i].deposito);   // POLIMORFICO
        cout << "Apos depositar R$ " << ops[i].deposito
             << ": R$ " << c.retSaldo() << "\n";

        c.debitar(ops[i].saque);       // POLIMORFICO
        cout << "Apos sacar     R$ " << ops[i].saque
             << ": R$ " << c.retSaldo() << "\n";

        // dynamic_cast para detectar ContaPoupanca e creditar juros
        ContaPoupanca *cp = dynamic_cast<ContaPoupanca*>(&c);
        if (cp) {
            double juros = cp->calculaJuros();
            cout << "Juros calculados: R$ " << juros << "\n";
            c.creditar(juros);
            cout << "Apos credito de juros: R$ " << c.retSaldo() << "\n";
        }
    }

    return 0;
}

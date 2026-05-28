// Exercicio 21.12 - main_Funcionario.cpp
// Folha de pagamento polimorfica com bonus de aniversario
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include "Funcionario.h"
#include "FuncionarioAssalariado.h"
#include "FuncionarioHorista.h"
#include "FuncionarioComissao.h"
#include "FuncionarioBaseMaisComissao.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);

    // Cria os funcionarios
    FuncionarioAssalariado f1("Joao", "Silva", "111.111.111-11",
                              Date(5, 15, 1985), 800.00);
    FuncionarioHorista     f2("Maria", "Santos", "222.222.222-22",
                              Date(11, 20, 1990), 25.00, 45);
    FuncionarioComissao    f3("Pedro", "Lima", "333.333.333-33",
                              Date(7, 8, 1980), 10000.00, 0.06);
    FuncionarioBaseMaisComissao f4("Ana", "Costa", "444.444.444-44",
                                   Date(3, 22, 1992), 8000.00, 0.04, 500.00);

    // Vector de REFERENCIAS a Funcionario (como pede o enunciado)
    // Usamos reference_wrapper porque vector nao aceita refs nativas.
    vector<reference_wrapper<Funcionario>> folha = { f1, f2, f3, f4 };

    // Descobre o mes atual do sistema
    time_t agora = time(nullptr);
    struct tm *partes = localtime(&agora);
    int mesAtual = partes->tm_mon + 1;
    cout << "=== Folha de pagamento (mes atual: " << mesAtual << ") ===\n\n";

    double totalFolha = 0;
    for (Funcionario &f : folha) {
        f.print();
        double pagamento = f.earnings();    // POLIMORFISMO!
        cout << "\n  Pagamento bruto: R$ " << pagamento;

        // Bonus de aniversario: +R$ 100 se mes atual = mes de nascimento
        if (f.getDataNascimento().getMes() == mesAtual) {
            cout << "\n  *** BONUS DE ANIVERSARIO: +R$ 100.00 ***";
            pagamento += 100.00;
        }
        cout << "\n  Pagamento final: R$ " << pagamento << "\n\n";
        totalFolha += pagamento;
    }

    cout << "Total da folha de pagamento: R$ " << totalFolha << endl;

    return 0;
}

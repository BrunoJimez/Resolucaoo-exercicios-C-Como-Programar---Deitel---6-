// Exercicio 21.14 - main_Tela.cpp
// Gerenciador de tela polimorfico
#include <iostream>
#include <vector>
#include <memory>
#include "FormaDesenhavel.h"
#include "QuadradoDes.h"
#include "RetanguloDes.h"
#include "TrianguloDes.h"
#include "CirculoDes.h"
using namespace std;

const int ALT_TELA = 20;
const int LAR_TELA = 50;

void limparTela(Tela &t) {
    for (auto &linha : t)
        for (auto &c : linha)
            c = '.';
}

void imprimirTela(const Tela &t) {
    // Moldura superior
    cout << "+";
    for (int j = 0; j < (int)t[0].size(); ++j) cout << "-";
    cout << "+\n";
    // Conteudo
    for (const auto &linha : t) {
        cout << "|";
        for (char c : linha) cout << c;
        cout << "|\n";
    }
    // Moldura inferior
    cout << "+";
    for (int j = 0; j < (int)t[0].size(); ++j) cout << "-";
    cout << "+\n";
}

// Gerenciador: redesenha TODAS as formas a cada chamada
void redesenharTela(Tela &t,
                    const vector<unique_ptr<FormaDesenhavel>> &formas) {
    limparTela(t);
    for (const auto &f : formas) {
        f->desenhar(t);     // CHAMADA POLIMORFICA!
    }
    imprimirTela(t);
}

int main() {
    Tela tela(ALT_TELA, vector<char>(LAR_TELA, '.'));
    vector<unique_ptr<FormaDesenhavel>> formas;

    cout << "=== Cenario pre-roteirizado: 4 formas adicionadas ===\n";

    formas.push_back(unique_ptr<FormaDesenhavel>(
        new QuadradoDes(2, 2, 5, '#')));
    cout << "\nApos adicionar " << formas.back()->descricao() << ":\n";
    redesenharTela(tela, formas);

    formas.push_back(unique_ptr<FormaDesenhavel>(
        new RetanguloDes(15, 3, 12, 6, '*')));
    cout << "\nApos adicionar " << formas.back()->descricao() << ":\n";
    redesenharTela(tela, formas);

    formas.push_back(unique_ptr<FormaDesenhavel>(
        new TrianguloDes(35, 4, 8, '+')));
    cout << "\nApos adicionar " << formas.back()->descricao() << ":\n";
    redesenharTela(tela, formas);

    formas.push_back(unique_ptr<FormaDesenhavel>(
        new CirculoDes(15, 14, 4, '@')));
    cout << "\nApos adicionar " << formas.back()->descricao() << ":\n";
    redesenharTela(tela, formas);

    return 0;
}

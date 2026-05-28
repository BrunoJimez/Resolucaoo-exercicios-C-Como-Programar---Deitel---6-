// Exercicio 17.15 - JogoVelha.cpp
#include <iostream>
#include "JogoVelha.h"
using namespace std;

JogoVelha::JogoVelha() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            tabuleiro[i][j] = 0;
}

void JogoVelha::exibir() const {
    cout << "\n     0   1   2\n";
    for (int i = 0; i < 3; ++i) {
        cout << "  " << i << "  ";
        for (int j = 0; j < 3; ++j) {
            char c = '.';
            if (tabuleiro[i][j] == 1) c = 'X';
            else if (tabuleiro[i][j] == 2) c = 'O';
            cout << c;
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "     ----+---+----\n";
    }
    cout << endl;
}

bool JogoVelha::jogar(int jogador, int linha, int coluna) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        cout << "Posicao fora do tabuleiro." << endl;
        return false;
    }
    if (tabuleiro[linha][coluna] != 0) {
        cout << "Casa ja ocupada." << endl;
        return false;
    }
    tabuleiro[linha][coluna] = jogador;
    return true;
}

bool JogoVelha::ganhou(int jogador) const {
    // Linhas e colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador
            && tabuleiro[i][2] == jogador) return true;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador
            && tabuleiro[2][i] == jogador) return true;
    }
    // Diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador
        && tabuleiro[2][2] == jogador) return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador
        && tabuleiro[2][0] == jogador) return true;
    return false;
}

bool JogoVelha::empate() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (tabuleiro[i][j] == 0) return false;
    return !ganhou(1) && !ganhou(2);
}

void JogoVelha::executarPartida() {
    int jogador = 1;
    while (true) {
        exibir();
        cout << "Jogador " << jogador << " ("
             << (jogador == 1 ? 'X' : 'O') << ")"
             << " - digite linha e coluna (0 a 2): ";
        int l, c;
        if (!(cin >> l >> c)) {
            cout << "Entrada invalida. Encerrando." << endl;
            return;
        }
        if (!jogar(jogador, l, c)) continue;

        if (ganhou(jogador)) {
            exibir();
            cout << ">>> JOGADOR " << jogador << " VENCEU! <<<" << endl;
            return;
        }
        if (empate()) {
            exibir();
            cout << ">>> EMPATE <<<" << endl;
            return;
        }
        jogador = (jogador == 1) ? 2 : 1;
    }
}

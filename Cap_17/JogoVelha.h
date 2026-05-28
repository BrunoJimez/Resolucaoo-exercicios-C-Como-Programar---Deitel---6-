// Exercicio 17.15 - JogoVelha.h
// Classe para jogo da velha (tic-tac-toe) de duas pessoas
#ifndef JOGOVELHA_H
#define JOGOVELHA_H

class JogoVelha {
public:
    // Estados possiveis de uma celula:
    //   0 = vazia, 1 = jogador 1, 2 = jogador 2
    JogoVelha();

    void exibir() const;
    bool jogar(int jogador, int linha, int coluna);   // retorna true se aceita
    bool ganhou(int jogador) const;
    bool empate() const;
    void executarPartida();

private:
    int tabuleiro[3][3];
};

#endif

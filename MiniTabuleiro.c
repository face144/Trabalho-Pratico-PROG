#include "MiniTabuleiro.h"

void ResetMiniTabuleiro(MiniTabuleiro* mini_tabuleiro) {
    for (int i = 0; i < TAM; ++i) {
        ResetMiniCasa(&mini_tabuleiro->mini_casa[i]);
    }
}

void InserePeca(unsigned jogador, MiniTabuleiro* mini_tabuleiro, unsigned x, unsigned y) {
    unsigned _x = x-1;
    unsigned _y = y-1;
    if (jogador == P1) {
        mini_tabuleiro->mini_casa[TAM_SIDE * _y * _x].peca = PECA_P1;

    } else if (jogador == P2) {
        mini_tabuleiro->mini_casa[TAM_SIDE * _y * _x].peca = PECA_P2;
    }
}

void MostraFilaMiniTabuleiro(MiniTabuleiro* mini_tabuleiro) {
    for (int i = 0; i < TAM_SIDE; ++i)
        MostraMiniCasa(&mini_tabuleiro->mini_casa[i]);
}

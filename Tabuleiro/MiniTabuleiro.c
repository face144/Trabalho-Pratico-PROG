#include "MiniTabuleiro.h"

void ResetMiniTabuleiro(MiniTabuleiro* mini_tabuleiro) {
    mini_tabuleiro->proprietario = PECA_VAZIA;
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

void MostraFilaMiniTabuleiro(MiniTabuleiro* mini_tabuleiro, unsigned fila) {
    int i;
    switch (fila) {
        case 1:
            i = 0;
            break;

        case 2:
            i = 3;
            break;

        case 3:
            i = 6;
            break;

        default:
            i = 0;
            break;
    }
    int diff = i;
    for (; i < TAM_SIDE + diff; ++i)
        MostraMiniCasa(&mini_tabuleiro->mini_casa[i]);
}

void MiniTabVerificaVitoria(MiniTabuleiro* mini_tabuleiro) {
    // Todo: Completar funcao
}
#include "MiniTabuleiro.h"

void ResetMiniTabuleiro(MiniTabuleiro* mini_tabuleiro) {
    mini_tabuleiro->proprietario = PECA_VAZIA;
    mini_tabuleiro->x_coord = -1;
    mini_tabuleiro->y_coord = -1;
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
    if (mini_tabuleiro->mini_casa[0].peca == mini_tabuleiro->mini_casa[1].peca &&
        mini_tabuleiro->mini_casa[1].peca == mini_tabuleiro->mini_casa[2].peca &&
        mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[0].peca;

    } else if (mini_tabuleiro->mini_casa[3].peca == mini_tabuleiro->mini_casa[4].peca &&
             mini_tabuleiro->mini_casa[4].peca == mini_tabuleiro->mini_casa[5].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[3].peca;

    } else if (mini_tabuleiro->mini_casa[6].peca == mini_tabuleiro->mini_casa[7].peca &&
             mini_tabuleiro->mini_casa[7].peca == mini_tabuleiro->mini_casa[8].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[6].peca;

    } else if (mini_tabuleiro->mini_casa[0].peca == mini_tabuleiro->mini_casa[3].peca &&
             mini_tabuleiro->mini_casa[3].peca == mini_tabuleiro->mini_casa[6].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[0].peca;

    } else if (mini_tabuleiro->mini_casa[1].peca == mini_tabuleiro->mini_casa[4].peca &&
             mini_tabuleiro->mini_casa[4].peca == mini_tabuleiro->mini_casa[7].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[1].peca;

    } else if (mini_tabuleiro->mini_casa[2].peca == mini_tabuleiro->mini_casa[5].peca &&
             mini_tabuleiro->mini_casa[5].peca == mini_tabuleiro->mini_casa[8].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[2].peca;

    } else if (mini_tabuleiro->mini_casa[0].peca == mini_tabuleiro->mini_casa[4].peca &&
             mini_tabuleiro->mini_casa[4].peca == mini_tabuleiro->mini_casa[8].peca &&
            mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[0].peca;

    } else if (mini_tabuleiro->mini_casa[2].peca == mini_tabuleiro->mini_casa[4].peca &&
             mini_tabuleiro->mini_casa[4].peca == mini_tabuleiro->mini_casa[6].peca &&
        mini_tabuleiro->mini_casa[0].peca != PECA_VAZIA) {
        mini_tabuleiro->proprietario = mini_tabuleiro->mini_casa[2].peca;

    } else
        mini_tabuleiro->proprietario = PECA_VAZIA;
}

unsigned MiniTabValidaEmpate(MiniTabuleiro* miniTabuleiro) {
    unsigned empate = FALSE;
    for (int i = 0; i < TAM; ++i) {
        if (miniTabuleiro->mini_casa[i].peca == PECA_VAZIA) {
            empate = FALSE;
            return empate;
        } else
            empate = TRUE;
    }
    return empate;
}

unsigned MiniTabuleiroCompleto(MiniTabuleiro* mini_tabuleiro) {
    if (mini_tabuleiro->proprietario != PECA_VAZIA)
        return TRUE;

    return FALSE;
}

#include "Tabuleiro.h"

void ResetTabuleiro(Tabuleiro* tabuleiro) {
    free(tabuleiro->mini_tabuleiro);

    tabuleiro->mini_tabuleiro = malloc(TAM * sizeof(MiniTabuleiro));
    for (int i = 0; i < TAM; ++i) {
        ResetMiniTabuleiro(&tabuleiro->mini_tabuleiro[i]);
    }
}

void MostraTabuleiro(Tabuleiro* tabuleiro) {
    printf("\n");
    for (int i = 0; i < TAM_SIDE; ++i) {
        printf(TETO);
    }
    for (int f = 1; f <= TAM_SIDE; ++f) {
        printf("\n");
        for (int i = 0; i < TAM_SIDE; ++i) {
            printf(BARRA);
            MostraFilaMiniTabuleiro(&tabuleiro->mini_tabuleiro[i], f);
            printf(BARRA);
        }
    }
    printf("\n");
    for (int i = 0; i < TAM_SIDE; ++i) {
        printf(TETO);
    }
    for (int f = 1; f <= TAM_SIDE; ++f) {
        printf("\n");
        for (int i = 3; i < 6; ++i) {
            printf(BARRA);
            MostraFilaMiniTabuleiro(&tabuleiro->mini_tabuleiro[i], f);
            printf(BARRA);
        }
    }
    printf("\n");
    for (int i = 0; i < TAM_SIDE; ++i) {
        printf(TETO);
    }
    for (int f = 1; f <= TAM_SIDE; ++f) {
        printf("\n");
        for (int i = 6; i < TAM; ++i) {
            printf(BARRA);
            MostraFilaMiniTabuleiro(&tabuleiro->mini_tabuleiro[i], f);
            printf(BARRA);
        }
    }
    printf("\n");
    for (int i = 0; i < TAM_SIDE; ++i) {
        printf(TETO);
    }
    printf("\n");
}

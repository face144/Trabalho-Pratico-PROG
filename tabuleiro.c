#include "tabuleiro.h"

void ResetTabuleiro(Tabuleiro* tabuleiro) {
    for (int i = 0; i < TAM; ++i) {
        free(tabuleiro->mini_tabuleiro + i);
    }

    tabuleiro->mini_tabuleiro = malloc(TAM * sizeof(MiniTabuleiro));
    for (int i = 0; i < TAM; ++i) {
        ResetMiniTabuleiro(&tabuleiro->mini_tabuleiro[i]);
    }
}

void MostraTabuleiro(Tabuleiro* tabuleiro) {
    // Fix deez nuts (formatação incorreta)
    for (int i = 0; i < TAM; ++i) {
        printf(TETO);
        for (int j = 0; j < TAM_SIDE; ++j) {
            printf(BARRA);
            MostraFilaMiniTabuleiro(&tabuleiro->mini_tabuleiro[i]);
            printf(BARRA);
        }

        printf("\n");
    }

}

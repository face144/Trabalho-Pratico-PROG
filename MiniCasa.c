#include "MiniCasa.h"

void ResetMiniCasa(MiniCasa* mini_casa) {
    mini_casa->peca = PECA_VAZIA;
}

void MostraMiniCasa(MiniCasa* mini_casa) {
    switch (mini_casa->peca) {

        case PECA_VAZIA:
            printf(" ");
            break;

        case PECA_P1:
            printf("X");
            break;

        case PECA_P2:
            printf("O");
            break;
    }
}

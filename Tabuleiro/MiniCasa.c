#include "MiniCasa.h"

void ResetMiniCasa(MiniCasa* mini_casa) {
    mini_casa->peca = PECA_VAZIA;
}

void MostraMiniCasa(MiniCasa* mini_casa) {
    switch (mini_casa->peca) {

        case PECA_VAZIA:
            printf(STR_PECA_VAZIA);
            break;

        case PECA_P1:
            printf(STR_PECA_P1);
            break;

        case PECA_P2:
            printf(STR_PECA_P2);
            break;
    }
}

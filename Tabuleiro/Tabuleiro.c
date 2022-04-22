#include "Tabuleiro.h"

void ResetTabuleiro(Tabuleiro* tabuleiro) {
    tabuleiro->mini_tabuleiro = NULL;
    free(tabuleiro->mini_tabuleiro);

    tabuleiro->mini_tabuleiro = malloc(TAM * sizeof(MiniTabuleiro));
    for (int i = 0; i < TAM_SIDE; ++i) {
        for (int j = 0; j < TAM_SIDE; ++j) {
            unsigned indice = TAM_SIDE * j + i;
            ResetMiniTabuleiro(&tabuleiro->mini_tabuleiro[indice]);
            tabuleiro->mini_tabuleiro[indice].x_coord = i + 1;
            tabuleiro->mini_tabuleiro[indice].y_coord = j + 1;
        }
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

unsigned TabVerificaVitoria(Tabuleiro* tabuleiro) {
    for (int i = 0; i < TAM; ++i) {
        MiniTabVerificaVitoria(&tabuleiro->mini_tabuleiro[i]);
    }

    printf("\n");
    for (int i = 0; i < TAM; ++i) {
        printf("Proprietario do Mini Tab. %d: %d\n", i, tabuleiro->mini_tabuleiro[i].proprietario);
    }

    if (tabuleiro->mini_tabuleiro[0].proprietario == tabuleiro->mini_tabuleiro[1].proprietario &&
        tabuleiro->mini_tabuleiro[1].proprietario == tabuleiro->mini_tabuleiro[2].proprietario &&
        tabuleiro->mini_tabuleiro[0].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[3].proprietario == tabuleiro->mini_tabuleiro[4].proprietario &&
               tabuleiro->mini_tabuleiro[4].proprietario == tabuleiro->mini_tabuleiro[5].proprietario &&
               tabuleiro->mini_tabuleiro[3].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[6].proprietario == tabuleiro->mini_tabuleiro[7].proprietario &&
               tabuleiro->mini_tabuleiro[7].proprietario == tabuleiro->mini_tabuleiro[8].proprietario &&
               tabuleiro->mini_tabuleiro[6].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[0].proprietario == tabuleiro->mini_tabuleiro[3].proprietario &&
               tabuleiro->mini_tabuleiro[3].proprietario == tabuleiro->mini_tabuleiro[6].proprietario &&
               tabuleiro->mini_tabuleiro[0].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[1].proprietario == tabuleiro->mini_tabuleiro[4].proprietario &&
               tabuleiro->mini_tabuleiro[4].proprietario == tabuleiro->mini_tabuleiro[7].proprietario &&
               tabuleiro->mini_tabuleiro[1].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[2].proprietario == tabuleiro->mini_tabuleiro[5].proprietario &&
               tabuleiro->mini_tabuleiro[5].proprietario == tabuleiro->mini_tabuleiro[8].proprietario &&
               tabuleiro->mini_tabuleiro[2].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[0].proprietario == tabuleiro->mini_tabuleiro[4].proprietario &&
               tabuleiro->mini_tabuleiro[4].proprietario == tabuleiro->mini_tabuleiro[8].proprietario &&
               tabuleiro->mini_tabuleiro[0].proprietario != PECA_VAZIA) {
        return TRUE;

    } else if (tabuleiro->mini_tabuleiro[2].proprietario == tabuleiro->mini_tabuleiro[4].proprietario &&
               tabuleiro->mini_tabuleiro[4].proprietario == tabuleiro->mini_tabuleiro[6].proprietario &&
               tabuleiro->mini_tabuleiro[2].proprietario != PECA_VAZIA) {
        return TRUE;

    } else return FALSE;
}

unsigned TabValidaEmpate(Tabuleiro* tabuleiro) {
    unsigned empate = FALSE;
    for (int i = 0; i < TAM; ++i) {
        if (MiniTabValidaEmpate(tabuleiro->mini_tabuleiro) == FALSE) {
            empate = FALSE;
            return empate;
        } else
            empate = TRUE;
    }
    return empate;
}

MiniTabuleiro* ProxMiniTabuleiroJogavel(Tabuleiro* tabuleiro, unsigned indice) {
    for (; indice < TAM; ++indice) {
        if (MiniTabuleiroCompleto(&tabuleiro->mini_tabuleiro[indice]) == FALSE) {
            return &tabuleiro->mini_tabuleiro[indice];
        }
    }
}

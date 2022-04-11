#ifndef TRABALHO_PRATICO_TABULEIRO_H
#define TRABALHO_PRATICO_TABULEIRO_H
#include "../common.h"
#include "MiniTabuleiro.h"
#include <stdlib.h>

typedef struct Tabuleiro {

    MiniTabuleiro* mini_tabuleiro;

}Tabuleiro;

void ResetTabuleiro(Tabuleiro* tabuleiro);
void MostraTabuleiro(Tabuleiro* tabuleiro);
unsigned TabVerificaVitoria (Tabuleiro* tabuleiro);

#endif //TRABALHO_PRATICO_TABULEIRO_H

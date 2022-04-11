#ifndef TRABALHO_PRATICO_MINITABULEIRO_H
#define TRABALHO_PRATICO_MINITABULEIRO_H
#include "../common.h"
#include "MiniCasa.h"

typedef struct MiniTabuleiro{

    MiniCasa mini_casa[9];


} MiniTabuleiro;

void ResetMiniTabuleiro(MiniTabuleiro* mini_tabuleiro);
void InserePeca(unsigned jogador, MiniTabuleiro* mini_tabuleiro, unsigned x, unsigned y);
void MostraFilaMiniTabuleiro(MiniTabuleiro* mini_tabuleiro, unsigned fila);

#endif //TRABALHO_PRATICO_MINITABULEIRO_H

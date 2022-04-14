#ifndef TRABALHO_PRATICO_MINITABULEIRO_H
#define TRABALHO_PRATICO_MINITABULEIRO_H
#include "../common.h"
#include "MiniCasa.h"
#include "../Jogador/Jogador.h"

typedef struct MiniTabuleiro{

    MiniCasa mini_casa[9];
    unsigned proprietario;
    int x_coord, y_coord;


} MiniTabuleiro;

void ResetMiniTabuleiro(MiniTabuleiro* mini_tabuleiro);
void InserePeca(unsigned jogador, MiniTabuleiro* mini_tabuleiro, unsigned x, unsigned y);
void MostraFilaMiniTabuleiro(MiniTabuleiro* mini_tabuleiro, unsigned fila);
void MiniTabVerificaVitoria(MiniTabuleiro* mini_tabuleiro);
unsigned MiniTabValidaEmpate(MiniTabuleiro* mini_tabuleiro);
unsigned MiniTabuleiroCompleto(MiniTabuleiro* mini_tabuleiro);

#endif //TRABALHO_PRATICO_MINITABULEIRO_H

#ifndef TRABALHO_PRATICO_JOGO_H
#define TRABALHO_PRATICO_JOGO_H
#include "../Jogador/Jogador.h"
#include "../Tabuleiro/Tabuleiro.h"
#include "../common.h"

typedef struct Jogada {

    unsigned x, y;
    MiniTabuleiro* mini_tabuleiro;
    Jogador* jogador;
    //struct Jogada* prox; // Lista ligada? Fix deez nutz plz
    // It's t minus 1 ohh ohh

} Jogada;

typedef struct Jogo {

    Jogador jogador[2];
    Tabuleiro tabuleiro;
    Jogada jogada;

} Jogo;

void Menu();
int ValidaEscolhaMenu(unsigned escolha);
void ProcecaEscolha(unsigned escolha);
void SalaJogo(unsigned bot);
void JogadaBOT();
unsigned ValidaJogada(Jogada* jogada);
void ModificaTabuleiro(Jogada* jogada);

#endif //TRABALHO_PRATICO_JOGO_H

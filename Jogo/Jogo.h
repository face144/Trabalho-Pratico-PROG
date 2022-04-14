#ifndef TRABALHO_PRATICO_JOGO_H
#define TRABALHO_PRATICO_JOGO_H
#include "../Jogador/Jogador.h"
#include "../Tabuleiro/Tabuleiro.h"
#include "../common.h"
#include <ctype.h>

typedef struct Jogada {

    unsigned x, y;
    MiniTabuleiro* mini_tabuleiro;
    Jogador* jogador;
    //struct Jogada* prox; // Lista ligada? Fix deez nutz plz
    // It's t minus 1 ohh ohh

} Jogada;

typedef struct Saveinfo {

    unsigned tam;
    Jogada* jogada;
    FILE* savefile;

}SaveInfo;

void InicializaSaveInfo(SaveInfo* save_info);
void GuardarJogadas(SaveInfo* save_info);
void AdicionaJogada(SaveInfo* save_info, Jogada* jogada);

typedef struct Jogo {

    Jogador jogador[2];
    Tabuleiro tabuleiro;
    Jogada jogada;
    SaveInfo save_info;

} Jogo;

void Menu();
int ValidaEscolhaMenu(unsigned escolha);
void ProcecaEscolha(unsigned escolha);
void SalaJogo(unsigned bot);
Jogada JogadaBOT(Jogo* jogo);
unsigned Validacoes(Jogada* jogada);
unsigned ValidaCoordenadas(Jogada* jogada);
unsigned ValidaCasa(Jogada* jogada);
void ModificaTabuleiro(Jogada* jogada);
unsigned ValidaFimJogo(Jogo* jogo);
MiniTabuleiro* MiniTabProxJogada(Tabuleiro* tabuleiro, unsigned* x, unsigned* y);

#endif //TRABALHO_PRATICO_JOGO_H

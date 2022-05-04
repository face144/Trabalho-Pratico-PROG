#ifndef TRABALHO_PRATICO_JOGO_H
#define TRABALHO_PRATICO_JOGO_H
#include "../Jogador/Jogador.h"
#include "../Tabuleiro/Tabuleiro.h"
#include "../listaligada/listaligada.h"
#include "../common.h"
#include <ctype.h>

typedef struct Jogada {

    unsigned x, y;
    MiniTabuleiro* mini_tabuleiro;
    Jogador* jogador;
    struct Jogada* prox;

} Jogada;



typedef struct Saveinfo {

    unsigned prox_jogador;
    Tabuleiro tabuleiro;
    Jogador jogadores[2];
    Jogada jogada;

}SaveInfo;

typedef struct Jogo {

    Jogador jogador[2];
    Tabuleiro tabuleiro;
    Jogada jogada;
    SaveInfo save_info;
    Node* ultimas_jogadas;

} Jogo;

void GuardarJogo(Jogo* jogo, unsigned j);
void Menu();
int ValidaEscolhaMenu(unsigned escolha, Jogo* jogo);
void ProcecaEscolha(unsigned escolha, Jogo* jogo);
void SalaJogo(unsigned escolha, Jogo* jogo);
Jogada JogadaBOT(Jogo* jogo);
unsigned Validacoes(Jogada* jogada);
unsigned ValidaCoordenadas(Jogada* jogada);
unsigned ValidaCasa(Jogada* jogada);
void ModificaTabuleiro(Jogada* jogada);
unsigned ValidaFimJogo(Jogo* jogo);
MiniTabuleiro* MiniTabProxJogada(Tabuleiro* tabuleiro, unsigned* x, unsigned* y);
void RetomaJogo(Jogo* jogo);
void ModoVisualisacao(Jogo *jogo);


#endif //TRABALHO_PRATICO_JOGO_H

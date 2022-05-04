#ifndef TRABALHO_PRATICO_LISTALIGADA_H
#define TRABALHO_PRATICO_LISTALIGADA_H
#include "../Tabuleiro/Tabuleiro.h"
#include "../Tabuleiro/Tabuleiro.h"
#include <stdlib.h>

struct Tabuleiro;

typedef struct Node {

    Tabuleiro tabuleiro;
    struct Node* prox;

} Node ;

void AdicionaJogada(struct Node** head_ref, Tabuleiro novo_tabuleiro);
void MostraJogadaAnterior(unsigned jogadas, Node *node);

#endif //TRABALHO_PRATICO_LISTALIGADA_H

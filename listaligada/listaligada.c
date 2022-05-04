#include "listaligada.h"

void AdicionaJogada(Node** head_ref, Tabuleiro novo_tabuleiro) {
    /* 1. allocate node */
    Node* node = malloc(sizeof(Node));

    /* 2. put in the data  */
    node->tabuleiro = novo_tabuleiro;

    /* 3. Make next of new node as head */
    node->prox = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = node;
}

void MostraJogadaAnterior(unsigned jogadas, Node *node) {

    for (int i = 0; i < jogadas; ++i) {
        if (node != NULL && node->prox != NULL)
            node = node->prox;

        else {
            printf("Erro: Numero de jogadas invalido.");
            return;
        }
    }

    printf("Modo visualisacao: Estado do tabuleiro ha %d jogadas atras.", jogadas);
    MostraTabuleiro(&node->tabuleiro);
    system("pause");
}



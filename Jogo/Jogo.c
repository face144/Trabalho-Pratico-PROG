#include "Jogo.h"

void Menu() {
    printf("--- TIC-TAC-TOE: Ultimate ---\n\n");

    printf("1 - Um jogador (P1 vs COM)\n");
    printf("2 - Dois jogadores (P1 vs P2)\n");
    printf("3 - Carregar ultimo jogo\n");
    printf("4 - Sair\n\n");

    unsigned escolha = 0;
    do {
        printf("Escolha:");
        scanf("%d", &escolha);
    } while (ValidaEscolhaMenu(escolha) == FALSE);
    ProcecaEscolha(escolha);
}

int ValidaEscolhaMenu(unsigned escolha) {
    if (escolha >= 1 && escolha <= 4)
        return TRUE;

    printf("Erro: Opcao invalida!\n");
    return FALSE;
}

void ProcecaEscolha(unsigned escolha) {
    switch (escolha) {
        case 1: // Um jogador
            SalaJogo(TRUE);
            break;

        case 2: // Dois jogadores
            SalaJogo(FALSE);
            break;

        case 3: // Carregar jogo (ficheiro binario)
            break;

        case 4: // exit(0) duuh
            exit(0);
            break;
    }
}

void SalaJogo(unsigned bot) {
    Jogo jogo;
    InicializaJogadores(jogo.jogador, bot);
    ResetTabuleiro(&jogo.tabuleiro);

    unsigned j = 0, x, y, mt;
    do {
        do {
            MostraTabuleiro(&jogo.tabuleiro);
            j++;
            if (j % 2 == 0) j = 2; else j = 1;

            // Remobere o mine tabuleire depois faixa bor
            if (bot == TRUE && j == 2) {
                // Jogada do bot
            } else {
                printf("Jogador %d (formato: 'mini tabuleiro' 'x' 'y'): ", j);
                scanf("%d %d %d", &mt, &x, &y);
            }
            jogo.jogada.jogador = &jogo.jogador[j - 1];
            jogo.jogada.mini_tabuleiro = &jogo.tabuleiro.mini_tabuleiro[mt - 1];
            jogo.jogada.x = x;
            jogo.jogada.y = y;
        } while (ValidaJogada(&jogo.jogada) == FALSE);
        ModificaTabuleiro(&jogo.jogada);
    } while (1 /*ValidaVitoria()*/);

}

unsigned ValidaJogada(Jogada* jogada) {
    if (jogada->x >= 1 && jogada->x <= 3 &&
        jogada->y >= 1 && jogada->y <= 3) {
        return TRUE;
    }

    printf("Erro: Jogada invalida!");
    return FALSE;
}

void ModificaTabuleiro(Jogada* jogada) {
    if (jogada->jogador->id == P1)
        jogada->mini_tabuleiro->mini_casa[TAM_SIDE * (jogada->y - 1) + (jogada->x - 1)].peca = PECA_P1;

    else if (jogada->jogador->id == P2 || jogada->jogador->id == BOT_ID)
        jogada->mini_tabuleiro->mini_casa[TAM_SIDE * (jogada->y - 1) + (jogada->x - 1)].peca = PECA_P2;
}

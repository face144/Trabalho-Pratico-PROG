#include "Jogo.h"

void InicializaSaveInfo(SaveInfo* save_info) {
    save_info->tam = 10;
    save_info->jogada = malloc(save_info->tam * sizeof(Jogada));
}

void GuardarJogadas(SaveInfo* save_info) {
    save_info->savefile = fopen("save.bin", "wb");

    if (!save_info->savefile) {
        printf("Erro: Erro ao abrir/criar ficheiro!\n");
        return;
    }

    fwrite(save_info->jogada, sizeof(Jogada), 1, save_info->savefile);
    fclose(save_info->savefile);
}

void AdicionaJogada(SaveInfo* save_info, Jogada* jogada) {
    for (unsigned i = 0; &save_info->jogada[i] != '\0' ; ++i) {
        if (&save_info->jogada[i] == NULL) {
            save_info->jogada[i] = *jogada;
        }
    }
    save_info->tam++;
    save_info->jogada = realloc(save_info->jogada, save_info->tam);
}

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

        default: // exit(0) duuh
            exit(0);
            break;
    }
}

void SalaJogo(unsigned bot) {
    Jogo jogo;
    InicializaSaveInfo(&jogo.save_info);
    InicializaJogadores(jogo.jogador, bot);
    ResetTabuleiro(&jogo.tabuleiro);

    unsigned j = 0, x = 1, y = 1, x_ant = 1, y_ant = 1;
    do {
        jogo.jogada.x = -1;
        jogo.jogada.y = -1;
        MostraTabuleiro(&jogo.tabuleiro);
        j++;
        unsigned indice = TAM_SIDE * (y_ant - 1) + (x_ant - 1);
        if (j % 2 == 0) j = 2; else j = 1;

        do {
            jogo.jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo.tabuleiro, indice);
            if (bot == TRUE && j == 2) {
                jogo.jogada = JogadaBOT(&jogo);
                jogo.jogada.jogador = &jogo.jogador[j - 1];

            } else {
                // jogo.jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo.tabuleiro, indice);
                unsigned x_coord = jogo.jogada.mini_tabuleiro->x_coord;
                unsigned y_coord = jogo.jogada.mini_tabuleiro->y_coord;
                printf("Tabuleiro x%d y%d : Jogador %d ('x' 'y'): ", x_coord, y_coord, j);
                scanf("%d %d",  &x, &y);
                jogo.jogada.jogador = &jogo.jogador[j - 1];
                jogo.jogada.x = x;
                jogo.jogada.y = y;
            }
        } while (Validacoes(&jogo.jogada) == FALSE);
        ModificaTabuleiro(&jogo.jogada);
        y_ant = y;
        x_ant = x;
        jogo.jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo.tabuleiro, indice);
        AdicionaJogada(&jogo.save_info, &jogo.jogada);
    } while (ValidaFimJogo(&jogo) == FALSE);
    GuardarJogadas(&jogo.save_info);
}

Jogada JogadaBOT(Jogo* jogo) {
    Jogada jogada_bot;
    jogada_bot.x = rand() % 3 + 1;
    jogada_bot.y = rand() % 3 + 1;
    return jogada_bot;
}

unsigned Validacoes(Jogada* jogada) {
    if (ValidaCoordenadas(jogada) == TRUE)
        if (ValidaCasa(jogada) == TRUE)
            return TRUE;

    return FALSE;
}

unsigned ValidaCoordenadas(Jogada* jogada) {
    if (jogada->x >= 1 && jogada->x <= 3 &&
        jogada->y >= 1 && jogada->y <= 3) {
        return TRUE;
    }


    printf("Erro: Coordenadas invalidas!\n");
    return FALSE;
}

unsigned ValidaCasa(Jogada* jogada) {
    if (jogada->mini_tabuleiro->mini_casa[TAM_SIDE * (jogada->y - 1) + (jogada->x - 1)].peca == PECA_VAZIA)
        return TRUE;

    printf("Erro: Casa ja contem uma peca!\n");
    return FALSE;
}

void ModificaTabuleiro(Jogada* jogada) {
    if (jogada->jogador->id == P1)
        jogada->mini_tabuleiro->mini_casa[TAM_SIDE * (jogada->y - 1) + (jogada->x - 1)].peca = PECA_P1;

    else if (jogada->jogador->id == P2 || jogada->jogador->id == BOT_ID)
        jogada->mini_tabuleiro->mini_casa[TAM_SIDE * (jogada->y - 1) + (jogada->x - 1)].peca = PECA_P2;
}

unsigned ValidaFimJogo(Jogo* jogo) {
    if (TabVerificaVitoria(&jogo->tabuleiro) == TRUE) {
        printf("Fim do jogo! Vencedor: Jogador %d\n", jogo->jogada.jogador->id);
        return TRUE;

    } else if (TabValidaEmpate(&jogo->tabuleiro) == TRUE) {
        printf("Fim do jogo. Empate!");
        return TRUE;
    }
    return FALSE;
}

MiniTabuleiro* MiniTabProxJogada(Tabuleiro* tabuleiro, unsigned* x, unsigned* y) {
    unsigned f = TAM_SIDE * (*y - 1) + (*x - 1);
    for (; f < TAM_SIDE; (*y)++) {
        for (; f < TAM_SIDE; (*x)++) {
            if (tabuleiro->mini_tabuleiro[f].proprietario == PECA_VAZIA)
                return &tabuleiro->mini_tabuleiro[f];
            f = TAM_SIDE * (*y - 1) + (*x - 1);
        }
    }
}

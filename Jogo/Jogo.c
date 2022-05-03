#include "Jogo.h"

void GuardarJogo(Jogo* jogo, unsigned j) {
    if (j == 1)
        j = 2;
    else
        j = 1;

    jogo->save_info.prox_jogador = j;
    jogo->save_info.tabuleiro = jogo->tabuleiro;
    for (int i = 0; i < 2; ++i) {
        jogo->save_info.jogadores[i] = jogo->jogador[i];
    }
    jogo->save_info.jogada = jogo->jogada;

    FILE* savefile = fopen("jogo.bin", "wb");

    if (!savefile) {
        printf("Erro: Erro ao guardar jogo!\n");
        return;
    }

    fwrite(&jogo->save_info, sizeof(SaveInfo), 1, savefile);
    fclose(savefile);
    printf("Sucesso: Jogo guardado!\n");
}

void Menu() {
    Jogo jogo;
    jogo.has_played = FALSE; // init

    printf("--- TIC-TAC-TOE: Ultimate ---\n\n");

    printf("1 - Um jogador (P1 vs COM)\n");
    printf("2 - Dois jogadores (P1 vs P2)\n");
    printf("3 - Carregar ultimo jogo\n");
    printf("4 - Sair\n\n");

    unsigned escolha = 0;
    do {
        printf("Escolha:");
        scanf("%d", &escolha);
    } while (ValidaEscolhaMenu(escolha, &jogo) == FALSE);

    ProcecaEscolha(escolha, &jogo);
}

int ValidaEscolhaMenu(unsigned escolha, Jogo* jogo) {
    if (escolha >= 1 && escolha <= 4) {
        if (escolha == 3 && jogo->has_played == FALSE) {
            printf("Erro: Nenhum jogo guardado.\n");
            return FALSE;

        } else return TRUE;

    } else {
        printf("Erro: Opcao invalida!\n");
        return FALSE;
    }
}

void ProcecaEscolha(unsigned escolha, Jogo* jogo) {
    if (escolha == 4) exit(0);
    else SalaJogo(escolha, jogo);
}

void SalaJogo(unsigned escolha, Jogo* jogo) {
    jogo->has_played = TRUE;
    unsigned bot = FALSE;
    if (escolha == 1) bot = TRUE; else if (escolha == 2) bot = FALSE;
    InicializaJogadores(jogo->jogador, bot);
    ResetTabuleiro(&jogo->tabuleiro);
    unsigned x = 1, y = 1, x_ant = 1, y_ant = 1;
    unsigned j = 0;
    if (escolha == 3) {
        RetomaJogo(jogo);
    }

    do {
        jogo->jogada.x = -1;
        jogo->jogada.y = -1;
        MostraTabuleiro(&jogo->tabuleiro);
        j++;
        unsigned indice = TAM_SIDE * (y_ant - 1) + (x_ant - 1);
        if (j % 2 == 0) j = 2; else j = 1;

        do {
            jogo->jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo->tabuleiro, indice);
            if (bot == TRUE && j == 2) {
                jogo->jogada = JogadaBOT(jogo);
                jogo->jogada.jogador = &jogo->jogador[j - 1];

            } else {
                // jogo.jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo.tabuleiro, indice);
                int x_coord = jogo->jogada.mini_tabuleiro->x_coord;
                int y_coord = jogo->jogada.mini_tabuleiro->y_coord;
                printf("Tabuleiro x%d y%d : Jogador %d ('x' 'y'): ", x_coord, y_coord, j);
                scanf("%d %d",  &x, &y);
                if (x == -1 && y == -1) {
                    GuardarJogo(jogo, j);
                    return;
                }

                // Todo: Listas ligadas aqui

                jogo->jogada.jogador = &jogo->jogador[j - 1];
                jogo->jogada.x = x;
                jogo->jogada.y = y;
            }
        } while (Validacoes(&jogo->jogada) == FALSE);

        ModificaTabuleiro(&jogo->jogada);
        y_ant = y;
        x_ant = x;
        jogo->jogada.mini_tabuleiro = ProxMiniTabuleiroJogavel(&jogo->tabuleiro, indice);
    } while (ValidaFimJogo(jogo) == FALSE);
    // GuardarJogadas(&jogo.save_info);
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

void RetomaJogo(Jogo* jogo) {
    FILE* savefile = fopen("jogo.bin", "rb");

    if (!savefile) {
        printf("Erro: Erro ao carregar jogo!\n");
        exit(0);
    }

    fread(&jogo->save_info, sizeof(SaveInfo), 1, savefile);
    fclose(savefile);

    jogo->tabuleiro = jogo->save_info.tabuleiro;
    for (int i = 0; i < 2; ++i) {
        jogo->jogador[i] = jogo->save_info.jogadores[i];
    }
    jogo->jogada = jogo->save_info.jogada;

    printf("Sucesso: Jogo carregado!\n");
}

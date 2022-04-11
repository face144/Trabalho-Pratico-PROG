#include "Jogador.h"

void InicializaJogadores(Jogador jogadores[], unsigned bot) {
    switch (bot) {
        case TRUE:
            jogadores[0].id = 1;
            jogadores[1].id = BOT_ID;
            break;

        case FALSE:
            jogadores[0].id = 1;
            jogadores[1].id = 2;
            break;
    }
}

cmake_minimum_required(VERSION 3.20)
project(Trabalho_Pratico C)

set(CMAKE_C_STANDARD 99)

add_executable(Trabalho_Pratico main.c Tabuleiro/MiniTabuleiro.c Tabuleiro/MiniTabuleiro.h Tabuleiro/MiniCasa.c Tabuleiro/MiniCasa.h common.h Tabuleiro/Tabuleiro.c Tabuleiro/Tabuleiro.h Jogador/Jogador.c Jogador/Jogador.h Jogo/Jogo.c Jogo/Jogo.h Ficheiros/Savegame.c Ficheiros/Savegame.h listaligada/listaligada.c listaligada/listaligada.h)

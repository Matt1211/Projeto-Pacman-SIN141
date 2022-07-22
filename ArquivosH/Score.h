#ifndef SCORE_H
#define SCORE_H
#include "Pacman.h"
#define spriteSize 33
#define PILULA '1'
#define MOEDA '2'
#define Vazio ' '


void playerScore(Pacman& player, int& pontos)
{
	if (mapa[player.getPosition_y() / spriteSize][player.getPosition_x() / spriteSize] == PILULA) {
		mapa[player.getPosition_y() / spriteSize][player.getPosition_x() / spriteSize] = Vazio;
		pontos++;
	}
	else if (mapa[player.getPosition_y() / spriteSize][player.getPosition_x() / spriteSize] == MOEDA) {
		mapa[player.getPosition_y() / spriteSize][player.getPosition_x() / spriteSize] = Vazio;
		pontos += 10;
	};
}

#endif
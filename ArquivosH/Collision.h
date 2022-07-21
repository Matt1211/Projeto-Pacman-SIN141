#ifndef COLLISION_H
#define COLLISION_H
#include "Pacman.h"
#include "Fantasma.h"

bool Colisao(Pacman& player, Fantasma& fantasma) {

	if (player.getPosition_y() == fantasma.getPosition_y()
		&&
		player.getPosition_x() == fantasma.getPosition_x())
	{
		return true;
	}

	return false;
}

#endif

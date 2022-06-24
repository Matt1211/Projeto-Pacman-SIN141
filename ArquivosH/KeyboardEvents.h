#ifndef KEYBOARDEVENTS_H
#define KEYBOARDEVENTS_H

#include <allegro5/allegro.h>
#include <iostream>
#include "MapUtils.h"
#include "Pacman.h"

using namespace std;

bool teclas[255] = { false }; //Vetor de Teclas

void pacmanFunction(char mapa[20][31]) {
	al_install_keyboard();

	Pacman pacmanObject;
	// Teclas Digitadas
	if (teclas[ALLEGRO_KEY_RIGHT]) {
		pacmanObject.setDirection(0);
	}
	else if (teclas[ALLEGRO_KEY_LEFT]) {
		pacmanObject.setDirection(1);
	} 
	else if (teclas[ALLEGRO_KEY_UP]) {
		pacmanObject.setDirection(2);
	}
	else if (teclas[ALLEGRO_KEY_DOWN]) {
		pacmanObject.setDirection(3);
	}

	// Posiionamento X
	if (pacmanObject.getDirection() == 0) {
		if (mapa[pacmanObject.getPosition_y() / 30][(pacmanObject.getPosition_x() - 30) / 30] != 'X')
			pacmanObject.setPosition_x(30, 0);
		else pacmanObject.setDirection(4);
	}

	if (pacmanObject.getDirection() == 1) {
		if (mapa[pacmanObject.getPosition_y() / 30][(pacmanObject.getPosition_x() + 30) / 30] != 'X')
			pacmanObject.setPosition_x(30, 1);
		else pacmanObject.setDirection(4);
	}

	// Posiionamento Y
	if (pacmanObject.getDirection() == 2) {
		if (mapa[(pacmanObject.getPosition_y() - 30) / 30][pacmanObject.getPosition_x() / 30] != 'X')
			pacmanObject.setPosition_y(30, 2);
		else pacmanObject.setDirection(4);
	}
	if (pacmanObject.getDirection() == 3) {
		if (mapa[(pacmanObject.getPosition_y() + 30) / 30][pacmanObject.getPosition_x() / 30] != 'X')
			pacmanObject.setPosition_y(30, 3);
		else pacmanObject.setDirection(4);
	}

	pacmanObject.renderizaPacman();

}

#endif // !KEYBOARDEVENTS_H


#ifndef MAPUTILS_H
#define MAPUTILS_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../ArquivosH/Moeda.h"
#include "../ArquivosH/Pilula.h"
#include "../ArquivosH/Tijolo.h"
#include "../ArquivosH/Pacman.h"

using namespace std;
const int LINHAS = 20;
const int COLUNAS = 31;
bool teclas[255] = { false }; //Vetor de Teclas
bool EXIT = false;

char mapa[LINHAS][COLUNAS] = {
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "Xoooo|ooooooXXXXXoooooo|ooooX",
  "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
  "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
  "XoooooooooooooooooooooooooooX",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoooooXXoooooXXXoooooXXoooooX",
  "XoXXXoXXXXXXoXXXoXXXXXXoXXXoX",
  "XoXXXoXXoooo|ooo|ooooXXoXXXoX",
  " oooooXXoXXXXXXXXXXXoXXooooo ",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoXXXoXXoooooooooooooXXoXXXoX",
  "XoXXXoXXXXXXoXXXoXXXXXXoXXXoX",
  "XoooooXXoooooXXXoooooXXoooooX",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoXXX|ooooooooooooooooo|XXXoX",
  "XoXXXoXXXXoXXXXXXXXoXXXoXXXoX",
  "XoXXXoXXXXooooooooooXXXoXXXoX",
  "Xoooo|oooooXXXXXXXXoooo|ooooX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};


void criarMapa() {
	Tijolo tijoloObject;
	Moeda moedaObject;
	Pilula pilulaObject;


	int linha, coluna;
	for (linha = 0; linha < LINHAS; linha++) {
		for (coluna = 0; coluna < COLUNAS; coluna++) {
			if (mapa[linha][coluna] == 'X') {
				tijoloObject.renderizaTijolo(linha, coluna);
			}
			else if (mapa[linha][coluna] == 'o') {
				moedaObject.renderizaMoeda(linha, coluna);
			}
			else if (mapa[linha][coluna] == '|') {
				pilulaObject.renderizaPilula(linha, coluna);
			};
		};
	};
};

void RenderizaMapa() {
	al_install_keyboard();

	Pacman pacmanObject;

	while (!EXIT) {
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

		criarMapa();
		pacmanObject.renderizaPacman();
		al_flip_display();
	};
}

#endif // !MAPUTILS_H

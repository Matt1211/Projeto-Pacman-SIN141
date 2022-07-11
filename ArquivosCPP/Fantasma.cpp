#include "../ArquivosH/Fantasma.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define FANTASMA_IMG "images/fantasma.bmp"
#define Tijolo '0'

Fantasma::Fantasma() {

	fantasmaBitmap = al_load_bitmap(FANTASMA_IMG);
	fantasmaDirection = 0;
	fantasmaPosition_x = 33 * 14;
	fantasmaPosition_y = 33 * 15;
	char map[20][30];

	renderizaFantasma(map);

}

Fantasma::~Fantasma() {

}


void Fantasma::setDirection() {

	this->fantasmaDirection = rand() % 3;
}

void Fantasma::setPosition_x(int position_x, char direction) {

	if (direction == 'R')
		this->fantasmaPosition_x -= position_x;

	if (direction == 'L')
		this->fantasmaPosition_x += position_x;

}
int Fantasma::getPosition_x() {

	return this->fantasmaPosition_x;
}

void Fantasma::setPosition_y(int position_y, char direction) {

	if (direction == 'U')
		this->fantasmaPosition_y -= position_y;

	if (direction == 'D')
		this->fantasmaPosition_y += position_y;

}

int Fantasma::getPosition_y() {

	return this->fantasmaPosition_y;
}

int Fantasma::getDirection() {

	return this->fantasmaDirection;
}

void Fantasma::segueDireita(char mapa[20][30])
{

	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() - 33) / 33] != Tijolo)
		this->setPosition_x(33, 'R');
	else this->setDirection();
}

void Fantasma::segueEsquerda(char mapa[20][30])
{

	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() + 33) / 33] != Tijolo)
		this->setPosition_x(33, 'L');
	else this->setDirection();
}

void Fantasma::segueAcima(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() - 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(33, 'U');
	else this->setDirection();
}

void Fantasma::segueAbaixo(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() + 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(33, 'D');
	else this->setDirection();
}

void Fantasma::renderizaFantasma(char mapa[20][30]) {

	al_draw_tinted_scaled_rotated_bitmap_region(
		fantasmaBitmap,
		33, //	sx - x da regiao na imagem
		0,					//	sy - y da regiao na imagem
		33,					//	sw - Largura da regiao na imagem
		33,					//	sh - Altura da regiao na imagem
		al_map_rgb(255, 255, 255),
		0,
		0,
		this->fantasmaPosition_x + 8,     //	dx - posicao x na tela
		this->fantasmaPosition_y + 6,	//	dy - posicao y na tela			
		0.901,
		0.901,
		0,
		0);

	if (getDirection() == 0) {
		segueDireita(mapa);
	}

	if (getDirection() == 1) {
		segueEsquerda(mapa);
	}

	if (getDirection() == 2) {
		segueAcima(mapa);
	}

	if (getDirection() == 3) {
		segueAbaixo(mapa);
	}

}
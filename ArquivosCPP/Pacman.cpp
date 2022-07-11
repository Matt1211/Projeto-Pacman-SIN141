#include "../ArquivosH/Pacman.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define PACMAN_IMG "images/pacman.jpeg"
#define Tijolo '0'

Pacman::Pacman() {

	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
	pacmanDirection = STILL;
	pacmanPosition_x = 8;
	pacmanPosition_y = 322;

	renderizaPacman(pacmanPosition_x, pacmanPosition_y, pacmanDirection);
}

Pacman::~Pacman() {

}

void Pacman::arredondamento() {
	this->pacmanPosition_x = ceil(this->pacmanPosition_x);
	this->pacmanPosition_y = ceil(this->pacmanPosition_y);
}


// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down; 4 = STILL
void Pacman::setDirection(int direction) {

	this->pacmanDirection = direction;
}

void Pacman::setPosition_x(int position_x, int direction) {

	if (this->getDirection() == RIGHT)
		this->pacmanPosition_x += position_x;

	if (this->getDirection() == LEFT)
		this->pacmanPosition_x -= position_x;

	this->setDirection(direction);
}
int Pacman::getPosition_x() {

	return this->pacmanPosition_x;
}

void Pacman::setPosition_y(int position_y, int direction) {

	if (this->getDirection() == UP)
		this->pacmanPosition_y -= position_y;

	if (this->getDirection() == DOWN)
		this->pacmanPosition_y += position_y;

	this->setDirection(direction);
}

int Pacman::getPosition_y() {

	return this->pacmanPosition_y;
}

int Pacman::getDirection() {

	return this->pacmanDirection;
}

void Pacman::segueDireita(char mapa[20][30])
{

	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() + 33) / 33] != Tijolo)
		this->setPosition_x(25, 0);
	else this->setDirection(4);
}
 
void Pacman::segueEsquerda(char mapa[20][30])
{

	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() - 33) / 33] != Tijolo)
		this->setPosition_x(25, 1);
	else this->setDirection(4);
}

void Pacman::segueAcima(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() - 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(25, 2);
	else this->setDirection(4);
}

void Pacman::segueAbaixo(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() + 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(25, 3);
	else this->setDirection(4);
}

void Pacman::renderizaPacman(int pacmanPositionX, int pacmanPositionY, int pacmanDirection) {

	al_draw_tinted_scaled_rotated_bitmap_region(
		pacmanBitmap,
		pacmanDirection * 33, //	sx - x da regiao na imagem
		0,					//	sy - y da regiao na imagem
		33,					//	sw - Largura da regiao na imagem
		33,					//	sh - Altura da regiao na imagem
		al_map_rgb(255, 255, 255),
		0,
		0,
		pacmanPositionX,     //	dx - posicao x na tela
		pacmanPositionY,		//	dy - posicao y na tela			
		0.901,
		0.901,
		0,
		0);
}
#include "../ArquivosH/Pacman.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#define PACMAN_IMG "images/pacman.jpeg"
#define Tijolo '0'
#define Moeda '1'
#define Pilula '2'

Pacman::Pacman() {

	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
	pacmanDirection = STILL;
	pacmanPosition_x = 33 * 14;
	pacmanPosition_y = 33 * 11;
	pontuacao = 0;
}

Pacman::~Pacman() {
}

void Pacman::arredondamento() {
	this->pacmanPosition_x = ceil(this->pacmanPosition_x);
	this->pacmanPosition_y = ceil(this->pacmanPosition_y);
}

void Pacman::setPontuacao(int pontuacao) {
	this->pontuacao = pontuacao;
}
int Pacman::getPontuacao() {
	return this->pontuacao;
};

void Pacman::checaPontuacao(char mapa[20][30], int posicaoX, int posicaoY)
{
	if (mapa[posicaoX / 33][posicaoY / 33] == Moeda)
		this->pontuacao++;

	if (mapa[posicaoX / 33][posicaoY / 33] == Pilula)
		this->pontuacao += 10;
}


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
		this->setPosition_x(33, RIGHT);
	else this->setDirection(STILL);
}

void Pacman::segueEsquerda(char mapa[20][30])
{

	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() - 33) / 33] != Tijolo)
		this->setPosition_x(33, LEFT);
	else this->setDirection(STILL);
}

void Pacman::segueAcima(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() - 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(33, UP);
	else this->setDirection(STILL);
}

void Pacman::segueAbaixo(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() + 33) / 33][this->getPosition_x() / 33] != Tijolo)
		this->setPosition_y(33, DOWN);
	else this->setDirection(STILL);
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
		pacmanPositionX + 8,     //	dx - posicao x na tela
		pacmanPositionY + 6,		//	dy - posicao y na tela			
		0.901,
		0.901,
		0,
		0);
}
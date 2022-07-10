#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.jpeg"


Pacman::Pacman() {
	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
	pacmanDirection = STILL;
	this->pacmanPosition_x = 33 * 14;
	this->pacmanPosition_y = 33 * 16;
}

Pacman::~Pacman() {}
// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down

void Pacman::setDirection(int direction) {
	this->pacmanDirection = direction;
} 

void Pacman::setPosition_x(int position_x, int direction) {
	if (direction == RIGHT) {
		this->pacmanPosition_x -= position_x;
	}

	if (direction == LEFT) {
		this->pacmanPosition_x += position_x;
	}
}
int Pacman::getPosition_x() {
	return this->pacmanPosition_x;
}

void Pacman::setPosition_y(int position_y, int direction) {
	if (direction == UP) {
		this->pacmanPosition_y -= position_y;
	}
	if (direction == DOWN) {
		this->pacmanPosition_y += position_y;
	}
}

int Pacman::getPosition_y() {
	return this->pacmanPosition_y;
}

int Pacman::getDirection() {
	return this->pacmanDirection;
}

void Pacman::segueDireita(char mapa[20][31])
{
	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() - 33) / 33] != 'X')
		this->setPosition_x(33, 0);
	else this->setDirection(0);
}

void Pacman::segueEsquerda(char mapa[20][31])
{
	if (mapa[this->getPosition_y() / 33][(this->getPosition_x() + 33) / 33] != 'X')
		this->setPosition_x(33, 1);
	else this->setDirection(0);
}

void Pacman::segueAcima(char mapa[20][31])
{
	if (mapa[(this->getPosition_y() - 33) / 33][this->getPosition_x() / 33] != 'X')
		this->setPosition_y(33, 2);
	else this->setDirection(0);
}

void Pacman::segueAbaixo(char mapa[20][31])
{
	if (mapa[(this->getPosition_y() + 33) / 33][this->getPosition_x() / 33] != 'X')
		this->setPosition_y(33, 3);
	else this->setDirection(0);
}

void Pacman::renderizaPacman() {
	al_draw_bitmap_region(pacmanBitmap, this->pacmanDirection * 33, 0, 33, 33, this->pacmanPosition_x + 8, this->pacmanPosition_y + 6, 0);
	//	sx - x da regiao na imagem
	//	sy - y da regiao na imagem
	//	sw - Largura da regiao na imagem
	//	sh - Altura da regiao na imagem
	//	dx - posicao x na tela
	//	dy - posicao y na tela
}
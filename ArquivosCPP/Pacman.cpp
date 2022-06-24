#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.bmp"

// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down

Pacman::Pacman() {
	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
	pacmanDirection = STILL;
}


Pacman::~Pacman() {

}

//olhar como estar usando direção
void Pacman::renderizaPacman() {
	al_draw_bitmap_region(pacmanBitmap, 0, this->pacmanDirection * 33, 0, 0, 0, 33, 33);
	/*al_draw_bitmap(pacmanBitmap, 33, 33, NULL);*/
}

void Pacman::setDirection(int direction) {

}

int Pacman::getDirection() {
	return this->pacmanDirection;
}

void Pacman::segueDireita(char mapa[20][31])
{
	if (mapa[this->getPosition_y() / 30][(this->getPosition_x() - 30) / 30] != 'X')
		this->setPosition_x(30, 0);
	else this->setDirection(4);
}

void Pacman::segueEsquerda(char mapa[20][31])
{
	if (mapa[this->getPosition_y() / 30][(this->getPosition_x() + 30) / 30] != 'X')
		this->setPosition_x(30, 1);
	else this->setDirection(4);
}

void Pacman::segueAcima(char mapa[20][31])
{
	if (mapa[(this->getPosition_y() - 30) / 30][this->getPosition_x() / 30] != 'X')
		this->setPosition_y(30, 2);
	else this->setDirection(4);
}

void Pacman::segueAbaixo(char mapa[20][31])
{
	if (mapa[(this->getPosition_y() + 30) / 30][this->getPosition_x() / 30] != 'X')
		this->setPosition_y(30, 3);
	else this->setDirection(4);
}

void Pacman::setPosition_x(int position_x, int direction) {
	if (direction == RIGHT) {
		this->pacmanPosition_x -= 30;
	}

	if (direction == LEFT) {
		this->pacmanPosition_x += 30;
	}
}
int Pacman::getPosition_x() {
	return this->pacmanPosition_x;
}

void Pacman::setPosition_y(int position_y, int direction) {
	if (direction == UP) {
		this->pacmanPosition_y -= 30;
	}
	if (direction == DOWN) {
		this->pacmanPosition_y += 30;
	}
}

int Pacman::getPosition_y() {
	return this->pacmanPosition_y;
}
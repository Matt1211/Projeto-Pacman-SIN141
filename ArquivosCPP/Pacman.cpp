#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.bmp"


Pacman::Pacman() {
	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
}


Pacman::~Pacman() {

}

void Pacman::renderizaPacman() {
	al_draw_bitmap_region(pacmanBitmap, 0, this->direction * 33, 0, 0, 0, 33, 33);
}

void Pacman::setDirection(int direction) {
	// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down
	if (direction == 1) this->direction = 1;
	else if (direction == 0)  this->direction = 0;
	else if (direction == 2)  this->direction = 2;
	else if (direction == 3)  this->direction = 3;
}

int Pacman::getDirection() {
	return this->direction;
}

void Pacman::setPosition_x(int position_x, int direction) {
	if (direction == 0) {
		this->position_x -= 30;
	}

	if (direction == 1) {
		this->position_x += 30;
	}
}
int Pacman::getPosition_x() {
	return this->position_x;
}

void Pacman::setPosition_y(int position_y, int direction) {
	if (direction == 2) {
		this->position_y -= 30;
	}
	if (direction == 3) {
		this->position_y += 30;
	}
}

int Pacman::getPosition_y() {
	return this->position_y;
}
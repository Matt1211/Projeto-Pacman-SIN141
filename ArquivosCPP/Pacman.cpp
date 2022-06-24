#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.bmp"

// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down

Pacman::Pacman() {
	pacmanBitmap = al_load_bitmap(PACMAN_IMG);
	pacmanDirection = RIGHT;
}


Pacman::~Pacman() {

}

//olhar como estar usando direção
void Pacman::renderizaPacman() {
	al_draw_bitmap_region(pacmanBitmap, 0, this->pacmanDirection * 33, 0, 0, 0, 33, 33);
}

void Pacman::setDirection(int direction) {

}

int Pacman::getDirection() {
	return this->pacmanDirection;
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
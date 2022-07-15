#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.jpeg"
#define INITIAL_X 462
#define INITIAL_Y 363

Pacman::Pacman() {
	this->position_x = INITIAL_X;
	this->position_y = INITIAL_Y;
	this->bitmap = al_load_bitmap(PACMAN_IMG);
	this->setDirection(STILL);
}

Pacman::~Pacman() {
}

void Pacman::arredondamento() {
	this->position_x = ceil(this->position_x);
	this->position_y = ceil(this->position_y);
}


void Pacman::setDirection(int direction) {

	this->direction = direction;
}

void Pacman::renderizaPacman(int pacmanPositionX, int pacmanPositionY, int pacmanDirection) {

	al_draw_tinted_scaled_rotated_bitmap_region(
		this->bitmap,
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
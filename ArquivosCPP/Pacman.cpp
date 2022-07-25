#include "../ArquivosH/Pacman.h"
#define PACMAN_IMG "images/pacman.jpeg"
#define INITIAL_X 462
#define INITIAL_Y 363
#define spriteSize 33

Pacman::Pacman() {
	this->position_x = INITIAL_X;
	this->position_y = INITIAL_Y;
	this->bitmap = al_load_bitmap(PACMAN_IMG);
	this->setDirection(STILL);

}

Pacman::~Pacman() {
}


void Pacman::setDirection(int direction) {

	this->direction = direction;
}

void Pacman::renderizaPacman() {

	al_draw_tinted_scaled_rotated_bitmap_region(
		this->bitmap,
		this->getDirection() * spriteSize, //	sx - x da regiao na imagem
		0,					//	sy - y da regiao na imagem
		spriteSize,					//	sw - Largura da regiao na imagem
		spriteSize,					//	sh - Altura da regiao na imagem
		al_map_rgb(255, 255, 255),
		0,
		0,
		this->getPosition_x() + 8,     //	dx - posicao x na tela
		this->getPosition_y() + 6,		//	dy - posicao y na tela			
		0.901,
		0.901,
		0,
		0);
}
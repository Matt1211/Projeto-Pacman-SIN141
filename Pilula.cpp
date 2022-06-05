#include <iostream>
#include <string.h>
#include "Pilula.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#define PILULA_IMG "images/pilula.png"

Pilula::Pilula() {
	pilula = al_load_bitmap(PILULA_IMG);
};

Pilula::~Pilula() {
};

void Pilula::drawPilula(int row, int col) {
	al_init_image_addon();
	al_draw_bitmap(pilula, col * 30 + 8, row * 30 + 6, 0);
};
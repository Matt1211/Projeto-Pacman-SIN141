#include <iostream>
#include <string.h>
#include "Moeda.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#define MOEDA_IMG "images/comida.png"

Moeda::Moeda() {
	moeda = al_load_bitmap(MOEDA_IMG);
};

Moeda::~Moeda() {
};

void Moeda::drawMoeda(int row, int col) {
	al_init_image_addon();
	al_draw_bitmap(moeda, col * 30 + 8, row * 30 + 8, 0);
};
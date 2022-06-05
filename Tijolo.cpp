#include <iostream>
#include <string.h>
#include "Tijolo.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#define TIJOLO_IMG "images/tijolo.png"

Tijolo::Tijolo() {
	tijolo = al_load_bitmap(TIJOLO_IMG);
};

Tijolo::~Tijolo() {
};

void Tijolo::drawTijolo(int row, int col) {
	al_init_image_addon();
	al_draw_bitmap(tijolo, col * 30, row * 30, 0);
};
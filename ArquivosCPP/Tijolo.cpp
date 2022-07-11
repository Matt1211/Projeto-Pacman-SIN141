#include "../ArquivosH/Tijolo.h"
#define TIJOLO_IMG "images/tijolo.png"

Tijolo::Tijolo() {
	tijoloBitmap = al_load_bitmap(TIJOLO_IMG);
}

Tijolo::~Tijolo() {

}

void Tijolo::renderizaTijolo(int linha, int coluna) {
	al_draw_scaled_bitmap(tijoloBitmap, 0, 0, 32, 31, coluna * 35 + 8, linha * 35 + 6, 32, 32, 0);
}
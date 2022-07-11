#include "../ArquivosH/Tijolo.h"
#define TIJOLO_IMG "images/tijolo.png"

Tijolo::Tijolo() {
	tijoloBitmap = al_load_bitmap(TIJOLO_IMG);
}

Tijolo::~Tijolo() {

}

void Tijolo::renderizaTijolo(int linha, int coluna) {
	al_draw_bitmap(tijoloBitmap, coluna * 35 + 8, linha * 35 + 6, 0);
}
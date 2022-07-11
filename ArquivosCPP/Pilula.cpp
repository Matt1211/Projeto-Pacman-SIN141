#include "../ArquivosH/Pilula.h"
#define PILULA_IMG "images/pilula.png"


Pilula::Pilula() {
	pilulaBitmap = al_load_bitmap(PILULA_IMG);
}


Pilula::~Pilula() {
}

void Pilula::renderizaPilula(int linha, int coluna) {
	al_draw_scaled_bitmap(pilulaBitmap, 0, 0, 18, 17, coluna * 33 + 12, linha * 33 + 12, 20, 20, 0);
}


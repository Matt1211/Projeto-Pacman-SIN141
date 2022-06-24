#include "../ArquivosH/Pilula.h"
#define PILULA_IMG "images/pilula.png"


Pilula::Pilula() {
	pilulaBitmap = al_load_bitmap(PILULA_IMG);
}


Pilula::~Pilula() {

}

void Pilula::renderizaPilula(int linha, int coluna) {
	al_draw_bitmap(pilulaBitmap, coluna * 35 + 12, linha * 35 + 12, 0);
}


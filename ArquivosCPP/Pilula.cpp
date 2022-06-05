#include "../ArquivosH/Pilula.h"
#define PILULA_IMG "images/pilula.png"


Pilula::Pilula() {
	pilulaBitmap = al_load_bitmap(PILULA_IMG);
}


Pilula::~Pilula() {

}

void Pilula::renderizaPilula(int linha, int coluna) {
	al_draw_bitmap(pilulaBitmap, (coluna * 30) + 8, (linha * 30) + 6, 0);
}


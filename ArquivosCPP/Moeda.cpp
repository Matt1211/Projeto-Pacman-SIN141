#include "../ArquivosH/Moeda.h"
#define MOEDA_IMG "images/comida.png"

Moeda::Moeda() {
	moedaBitmap = al_load_bitmap(MOEDA_IMG);
}

Moeda::~Moeda() {

}

void Moeda::renderizaMoeda(int linha, int coluna) {
	al_draw_bitmap(moedaBitmap, coluna * 30 + 12, linha * 30 + 12, 0);
}
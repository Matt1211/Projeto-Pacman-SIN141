#include "../ArquivosH/Moeda.h"
#define MOEDA_IMG "images/comida.png"

Moeda::Moeda() {
	moedaBitmap = al_load_bitmap(MOEDA_IMG);
}

Moeda::~Moeda() {

}

void Moeda::renderizaMoeda(int linha, int coluna) {
	al_draw_scaled_bitmap(moedaBitmap, 0, 0, 17, 11, coluna * 35 + 12, linha * 35 + 12, 15, 15, 0);
}
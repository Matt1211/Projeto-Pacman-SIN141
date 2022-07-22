#include "../ArquivosH/FantasmaSmart.h"
#define FANTASMA_LARANJA_IMG "images/fantasmaLaranja.bmp"
#define INITIAL_X 462
#define INITIAL_Y 495
#define spriteSize 33
#define TIJOLO '0'

FantasmaSmart::FantasmaSmart() {

	this->position_x = INITIAL_X;
	this->position_y = INITIAL_Y;
	this->direction = STILL;

}

FantasmaSmart::FantasmaSmart(int position_x, int position_y) {

	this->bitmap = al_load_bitmap(FANTASMA_LARANJA_IMG);
	this->position_x = spriteSize * position_x;
	this->position_y = spriteSize * position_y;

}

FantasmaSmart::~FantasmaSmart() {

}

void FantasmaSmart::setDirection(int direction) {

	this->direction = rand() % 4;
}
void FantasmaSmart::IA_Base(char mapa[20][30])
{
		this->setDirection(rand() % (4 * this->getPosition_x() * this->getPosition_y()));
}
void FantasmaSmart::renderizaFantasma(char mapa[20][30], int pac_pos_x, int pac_pos_y) {

	al_draw_bitmap_region(this->bitmap, 0, 0, spriteSize, spriteSize, this->getPosition_x() + 8, this->getPosition_y() + 6, 0);

	if ((this->getPosition_x() < pac_pos_x)) {
		this->segueEsquerda(mapa);

	}

	else if ((this->getPosition_x() > pac_pos_x)) {
		this->segueDireita(mapa);

	}

	else if ((this->getPosition_y() < pac_pos_y)) {
	this->segueAbaixo(mapa);

	}

	else if ((this->getPosition_y() > pac_pos_y)) {
		this->segueAcima(mapa);
	}

	else {
		IA_Base(mapa);
	}
}

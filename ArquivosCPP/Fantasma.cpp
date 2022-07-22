#include "../ArquivosH/Fantasma.h"
#define FANTASMA_AMARELO_IMG "images/fantasmaAmarelo.bmp"
#define FANTASMA_AZUL_IMG "images/fantasmaAzul.bmp"
#define FANTASMA_ROSA_IMG "images/fantasmaRosa.bmp"
#define INITIAL_X 462
#define INITIAL_Y 495
#define spriteSize 33
#define TIJOLO '0'

Fantasma::Fantasma() {

	this->position_x = INITIAL_X;
	this->position_y = INITIAL_Y;
	this->direction = STILL;
	this->cor = NULL;
}

Fantasma::Fantasma(int cor, int position_x, int position_y) {

	switch (cor)
	{
	case AMARELO:
		this->bitmap = al_load_bitmap(FANTASMA_AMARELO_IMG);
		break;

	case AZUL:
		this->bitmap = al_load_bitmap(FANTASMA_AZUL_IMG);
		break;

	case ROSA:
		this->bitmap = al_load_bitmap(FANTASMA_ROSA_IMG);
		break;

	default:
		break;
	}

	this->setDirection(0);
	this->position_x = spriteSize * position_x;
	this->position_y = spriteSize * position_y;

}

Fantasma::~Fantasma() {

}

int Fantasma::getCor() {
	return this->cor;
}

void Fantasma::setDirection(int direction) {

	this->direction = rand() % 4;
}

void Fantasma::IA_Base(char mapa[20][30])
{
	if (mapa[this->getPosition_y() / spriteSize][this->getPosition_x() / spriteSize] == TIJOLO) {
		this->setDirection(rand() % (4 * this->getPosition_x() * this->getPosition_y()));
	}

	switch (this->getDirection())
	{
	case RIGHT:
		this->segueDireita(mapa);
		break;

	case LEFT:
		this->segueEsquerda(mapa);
		break;

	case UP:
		this->segueAcima(mapa);
		break;

	case DOWN:
		this->segueAbaixo(mapa);
		break;

	default:
		break;
	}
}

void Fantasma::renderizaFantasma(char mapa[20][30]) {

	IA_Base(mapa);
	al_draw_bitmap_region(this->bitmap, 0, 0, spriteSize, spriteSize, this->getPosition_x() + 8, this->getPosition_y() + 6, 0);
}



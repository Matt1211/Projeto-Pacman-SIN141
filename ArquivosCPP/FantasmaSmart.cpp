#include "../ArquivosH/FantasmaSmart.h"
#define FANTASMA_LARANJA_IMG "images/fantasmaLaranja.bmp"
#define INITIAL_X 462
#define INITIAL_Y 495
#define spriteSize 33
#define TIJOLO '0'

FantasmaSmart::FantasmaSmart()
{

	this->position_x = INITIAL_X;
	this->position_y = INITIAL_Y;
	this->direction = STILL;
}

FantasmaSmart::FantasmaSmart(int position_x, int position_y)
{

	this->bitmap = al_load_bitmap(FANTASMA_LARANJA_IMG);
	this->position_x = spriteSize * position_x;
	this->position_y = spriteSize * position_y;
}

FantasmaSmart::~FantasmaSmart()
{

}

void FantasmaSmart::IA_Smart(char mapa[20][30], int pac_pos_x, int pac_pos_y)
{

	int x_distance = abs(this->getPosition_x() - pac_pos_x);
	int y_distance = abs(this->getPosition_y() - pac_pos_y);

	if (x_distance < y_distance) {
		switch (this->getDirection())
		{
		case RIGHT:
			this->segueDireita(mapa);
			break;

		case LEFT:
			this->segueEsquerda(mapa);
			break;
		default:
			IA_Base(mapa);
			break;
		}
	}
	else
	{
		switch (this->getDirection())
		{
		case UP:
			this->segueAcima(mapa);
			break;

		case DOWN:
			this->segueAbaixo(mapa);
			break;
		default:
			IA_Base(mapa);
			break;
		}
	}
	/*if ((this->getPosition_x() > pac_pos_x) && (mapa[(this->getPosition_y() / spriteSize)][(this->getPosition_x() - spriteSize) / spriteSize] != TIJOLO))
	{
		this->segueEsquerda(mapa);
	}

	else if ((this->getPosition_x() < pac_pos_x) && (mapa[this->getPosition_y() / spriteSize][(this->getPosition_x() + spriteSize) / spriteSize] != TIJOLO))
	{
		this->segueDireita(mapa);
	}

	else if ((this->getPosition_y() > pac_pos_y) && (mapa[(this->getPosition_y() - spriteSize) / spriteSize][this->getPosition_x() / spriteSize] != TIJOLO))
	{
		this->segueAbaixo(mapa);
	}

	else if ((this->getPosition_y() < pac_pos_y) && (mapa[(this->getPosition_y() + spriteSize) / spriteSize][this->getPosition_x() / spriteSize] != TIJOLO))
	{
		this->segueAcima(mapa);
	}*/

	/*if (mapa[this->getPosition_y() / spriteSize][this->getPosition_x() / spriteSize] == TIJOLO)
		IA_Base(mapa);*/

}

void FantasmaSmart::renderizaFantasma(char mapa[20][30], int pac_pos_x, int pac_pos_y) {

	IA_Smart(mapa, pac_pos_x, pac_pos_y);
	al_draw_bitmap_region(this->bitmap, 0, 0, spriteSize, spriteSize, this->getPosition_x() + 8, this->getPosition_y() + 6, 0);

}

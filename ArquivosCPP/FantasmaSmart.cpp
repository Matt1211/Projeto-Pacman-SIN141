#include "../ArquivosH/FantasmaSmart.h"
#define FANTASMA_LARANJA_IMG "images/fantasmaLaranja.bmp"
#define INITIAL_X 462
#define INITIAL_Y 495
#define spriteSize 33
#define TIJOLO '0'
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

	if ((this->position_x > pac_pos_x) && (mapa[(this->getPosition_y() / spriteSize)][(this->getPosition_x() - spriteSize) / spriteSize] != TIJOLO))
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
	}

	else if ((this->getPosition_x() > pac_pos_x) && (mapa[this->getPosition_y() / spriteSize][(this->getPosition_x() - spriteSize) / spriteSize] != TIJOLO))
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
	}

	if (mapa[this->getPosition_y() / spriteSize][this->getPosition_x() / spriteSize] == TIJOLO) {
		this->setDirection(rand() % (4 * this->getPosition_x() * this->getPosition_y()));
	}
	else {
		this->direction = rand() % 3;
	}

}

void FantasmaSmart::renderizaFantasma(char mapa[20][30], int pac_pos_x, int pac_pos_y) {

	IA_Smart(mapa, pac_pos_x, pac_pos_y);
	al_draw_bitmap_region(this->bitmap, 0, 0, spriteSize, spriteSize, this->getPosition_x() + 8, this->getPosition_y() + 6, 0);

}

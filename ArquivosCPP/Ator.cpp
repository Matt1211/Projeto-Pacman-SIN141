#include "../ArquivosH/Ator.h"
#define TIJOLO '0'
#define MOEDA '1'
#define PILULA '2'
#define spriteSize 33

int Ator::getPosition_x()
{
	return this->position_x;
}

int Ator::getPosition_y()
{
	return this->position_y;
}

int Ator::getDirection()
{
	return this->direction;
}

void Ator::setPosition_x(int position_x)
{
	if (this->getDirection() != STILL) {

		if (this->getDirection() == RIGHT)
			this->position_x += position_x;

		if (this->getDirection() == LEFT)
			this->position_x -= position_x;
	}
}

void Ator::setPosition_y(int position_y)
{
	if (this->getDirection() != STILL) {

		if (this->getDirection() == UP)
			this->position_y -= position_y;

		if (this->getDirection() == DOWN)
			this->position_y += position_y;
	}
}

void Ator::segueDireita(char mapa[20][30])
{
	if (mapa[this->getPosition_y() / spriteSize][(this->getPosition_x() + spriteSize) / spriteSize] != TIJOLO)
		this->setPosition_x(spriteSize);
	else
		this->setDirection(STILL);
}

void Ator::segueEsquerda(char mapa[20][30]) {
	if (mapa[this->getPosition_y() / spriteSize][(this->getPosition_x() - spriteSize) / spriteSize] != TIJOLO)
		this->setPosition_x(spriteSize);
	else
		this->setDirection(STILL);
}

void Ator::segueAcima(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() - spriteSize) / spriteSize][this->getPosition_x() / spriteSize] != TIJOLO)
		this->setPosition_y(spriteSize);
	else
		this->setDirection(STILL);
}

void Ator::segueAbaixo(char mapa[20][30])
{
	if (mapa[(this->getPosition_y() + spriteSize) / spriteSize][this->getPosition_x() / spriteSize] != TIJOLO)
		this->setPosition_y(spriteSize);
	else
		this->setDirection(STILL);
}
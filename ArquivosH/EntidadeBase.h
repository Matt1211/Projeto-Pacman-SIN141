#ifndef ENTIDADEBASE_H
#define ENTIDADEBASE_H
#include <allegro5/allegro.h>
#include "Map.h"

enum directionEnum {
	RIGHT = 1,
	LEFT = 0,
	UP = 2,
	DOWN = 3,
	STILL = 4
};

class EntidadeBase
{
public:

	virtual void setPosition_x(int position_x, char direction) = 0;
	virtual int getPosition_x() = 0;

	virtual void setPosition_y(int position_y, char direction) = 0;
	virtual int getPosition_y() = 0;

	virtual void setDirection() = 0;
	virtual int getDirection() = 0;

	virtual void segueDireita(char mapa[20][30]) = 0;

	virtual void segueEsquerda(char mapa[20][30]) = 0;

	virtual void segueAcima(char mapa[20][30]) = 0;

	virtual void segueAbaixo(char mapa[20][30]) = 0;

private:
	int entityDirection;
	int entityPosition_x;
	int entityPosition_y;
};

#endif // !MOVIMENTACAO_H


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

	EntidadeBase();
	~EntidadeBase();

	void setPosition_x(int position_x, char direction);
	int getPosition_x();

	void setPosition_y(int position_y, char direction);
	int getPosition_y();

	virtual void setDirection() = 0;
	int getDirection();

	void segueDireita(char mapa[20][30]);

	void segueEsquerda(char mapa[20][30]);

	void segueAcima(char mapa[20][30]);

	void segueAbaixo(char mapa[20][30]);

private:
	int entityDirection;
	int entityPosition_x;
	int entityPosition_y;
};

#endif // !MOVIMENTACAO_H


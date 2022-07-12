#ifndef FANTASMA_H
#define	FANTASMA_H
#include <allegro5/allegro.h>
#include "Map.h"

class Fantasma
{
public:
	Fantasma();
	Fantasma(char cor, int position_x, int position_y);
	~Fantasma();

	void renderizaFantasma(char mapa[20][30]);

	void setPosition_x(int position_x, char direction);
	int getPosition_x();

	void setPosition_y(int position_y, char direction);
	int getPosition_y();

	void setDirection();
	int getDirection();

	void segueDireita(char mapa[20][30]);

	void segueEsquerda(char mapa[20][30]);

	void segueAcima(char mapa[20][30]);

	void segueAbaixo(char mapa[20][30]);

private:
	char cor;
	int fantasmaDirection;
	int fantasmaPosition_x;
	int fantasmaPosition_y;
	ALLEGRO_BITMAP* fantasmaBitmap;
};

#endif // !FANTASMA_H

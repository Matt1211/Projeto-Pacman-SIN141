#ifndef PACMAN_H
#define	PACMAN_H
#include <allegro5/allegro.h>
#include "Map.h"

class Pacman
{
public:
	Pacman();
	~Pacman();

	void renderizaPacman(int pacmanPositionX, int pacmanPositionY, int pacmanDirection);

	void setPosition_x(int position_x, int direction);
	int getPosition_x();

	void setPosition_y(int position_y, int direction);
	int getPosition_y();

	void setDirection(int direction);
	int getDirection();

	void segueDireita(char mapa[20][30]);

	void segueEsquerda(char mapa[20][30]);

	void segueAcima(char mapa[20][30]);

	void segueAbaixo(char mapa[20][30]);

	void arredondamento();

private:
	int pacmanDirection;
	int pacmanPosition_x;
	int pacmanPosition_y;
	ALLEGRO_BITMAP* pacmanBitmap;
};

#endif // !PACMAN_H


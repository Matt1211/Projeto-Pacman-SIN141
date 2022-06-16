#ifndef PACMAN_H
#define	PACMAN_H
#include <allegro5/allegro.h>

class Pacman
{
public:
	Pacman();
	~Pacman();

	void renderizaPacman();

	int setPosition_x(int position_x, int direction);
	int getPosition_x();

	int setPosition_y(int position_y, int direction);
	int getPosition_y();

	int setDirection(int direction);
	int getDirection();

private:
	int direction = 0;
	int position_x = 30 * 14;
	int position_y = 30 * 16;
	ALLEGRO_BITMAP* pacmanBitmap;
};

#endif // !PACMAN_H


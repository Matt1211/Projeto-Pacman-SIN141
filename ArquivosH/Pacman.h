#ifndef PACMAN_H
#define	PACMAN_H
#include <allegro5/allegro.h>

// 0 = Rigth; 1 = Left; 2 = UP; 3 = Down

enum directionEnum {
	RIGHT = 0,
	LEFT = 1,
	UP = 2,
	DOWN = 3
};

class Pacman
{
public:
	Pacman();
	~Pacman();

	void renderizaPacman();

	void setPosition_x(int position_x, int direction);
	int getPosition_x();

	void setPosition_y(int position_y, int direction);
	int getPosition_y();

	void setDirection(int direction);
	int getDirection();

private:
	int pacmanDirection;
	int pacmanPosition_x = 30 * 14;
	int pacmanPosition_y = 30 * 16;
	ALLEGRO_BITMAP* pacmanBitmap;
};

#endif // !PACMAN_H


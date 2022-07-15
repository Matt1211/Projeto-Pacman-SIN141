#ifndef PACMAN_H
#define	PACMAN_H
#include <allegro5/allegro.h>
#include "Ator.h"
#include <math.h>

class Pacman : public Ator
{
public:

	Pacman();
	~Pacman();

	void arredondamento();
	void setDirection(int direction);
	void renderizaPacman();
};

#endif // !PACMAN_H


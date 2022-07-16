#ifndef ATOR_H
#define ATOR_H
#include <iostream>
#include <allegro5/allegro.h>

using namespace std;


enum directionEnum {

	RIGHT = 1,
	LEFT = 0,
	UP = 2,
	DOWN = 3,
	STILL = 4

};

enum colorEnum {

	AMARELO = 0,
	AZUL = 1,
	LARANJA = 2,
	ROSA = 3

};

class Ator
{
public:

	int getPosition_x();
	int getPosition_y();
	int getDirection();
	virtual void setDirection(int direction) = 0;
	void setPosition_x(int position_x);
	void setPosition_y(int position_y);
	void segueDireita(char mapa[20][30]);
	void segueEsquerda(char mapa[20][30]);
	void segueAcima(char mapa[20][30]);
	void segueAbaixo(char mapa[20][30]);

protected:

	int position_x;
	int position_y;
	int direction;
	ALLEGRO_BITMAP* bitmap;
};

#endif // ATOR


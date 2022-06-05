#ifndef Pilula_h
#define Pilula_h
#include <allegro5/allegro.h>

class Pilula {
public:
	Pilula();
	~Pilula();

	void drawPilula(int row, int col);

private:
	ALLEGRO_BITMAP* pilula;
};

#endif

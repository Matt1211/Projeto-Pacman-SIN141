#ifndef Moeda_h
#define Moeda_h
#include <allegro5/allegro.h>

class Moeda {
public:
	Moeda();
	~Moeda();

	void drawMoeda(int row, int col);

private:
	ALLEGRO_BITMAP* moeda;
};

#endif

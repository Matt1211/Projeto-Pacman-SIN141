#ifndef Tijolo_h
#define Tijolo_h
#include <allegro5/allegro.h>

class Tijolo{
public:
	Tijolo(); 
	~Tijolo(); 

	void drawTijolo(int row, int col);

private:
	ALLEGRO_BITMAP* tijolo;
};

#endif

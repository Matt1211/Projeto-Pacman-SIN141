#ifndef TIJOLO_H
#define TIJOLO_H
#include <allegro5/allegro.h>

class Tijolo
{
public:
	Tijolo();
	~Tijolo();
	void renderizaTijolo(int linha, int coluna);
private:
	ALLEGRO_BITMAP* tijoloBitmap;
};

#endif // !TIJOLO_H
#ifndef PILULA_H
#define	PILULA_H
#include <allegro5/allegro.h>

class Pilula
{
public:
	Pilula();
	~Pilula();
	void renderizaPilula(int linha, int coluna);
private:
	ALLEGRO_BITMAP* pilulaBitmap;
};

#endif // !PILULAS_H


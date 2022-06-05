#ifndef MOEDA_H
#define MOEDA_H
#include <allegro5/allegro.h>

class Moeda
{
public:
	Moeda();
	~Moeda();
	void renderizaMoeda(int linha, int coluna);
private:
	ALLEGRO_BITMAP* moedaBitmap;
};

#endif // !MOEDA_H


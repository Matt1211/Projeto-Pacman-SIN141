#ifndef FANTASMA_H
#define	FANTASMA_H
#include <allegro5/allegro.h>
#include "Map.h"
#include "Ator.h"
#include <math.h>

class Fantasma : public Ator
{
public:
	Fantasma();
	Fantasma(int cor, int position_x, int position_y);
	~Fantasma();

	void setDirection(int direction);
	virtual void renderizaFantasma(char mapa[20][30]);

protected:
	int cor;

private:
	void IA_Base(char mapa[20][30]);
};

#endif // !FANTASMA_H

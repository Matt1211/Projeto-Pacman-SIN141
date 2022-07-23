#ifndef FANTASMASMART_H
#define FANTASMASMART_H
#include <allegro5/allegro.h>
#include "Map.h"
#include "Ator.h"
#include <math.h>

class FantasmaSmart : public Ator
{
public:
	FantasmaSmart();
	FantasmaSmart(int position_x, int position_y);
	~FantasmaSmart();

	void setDirection(int direction);
	virtual void renderizaFantasma(char mapa[20][30], int pac_pos_x, int pac_pos_y);
private:
	void IA_Smart(char mapa[20][30], int pac_pos_x, int pac_pos_y);
};

#endif // !FANTASMASMART_H
#ifndef FANTASMASMART_H
#define FANTASMASMART_H
#include "Fantasma.h"
#include "Pacman.h"


class FantasmaSmart : public Fantasma
{
public:
	FantasmaSmart();
	FantasmaSmart(int cor, int position_x, int position_y);
	~FantasmaSmart();


	void renderizaFantasma(char mapa[20][30]);

private:
	void IASmart(char mapa[20][30]);
};

#endif // !FANTASMASMART_H

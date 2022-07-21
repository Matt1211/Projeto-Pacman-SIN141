#include "../ArquivosH/FantasmaSmart.h"

FantasmaSmart::FantasmaSmart(){

}

FantasmaSmart::FantasmaSmart(int cor, int position_x, int position_y) : Fantasma(cor, position_x, position_y) {
	this->cor = cor;
	this->position_x = position_x;
	this->position_y = position_y;
}

FantasmaSmart::~FantasmaSmart() {

}

void FantasmaSmart::renderizaFantasma(char mapa[20][30])
{

}

//int FantasmaSmart::getPlayer_x(Pacman& player) {
//	return player.getPosition_x();
//}
//
//int FantasmaSmart::getPlayer_y(Pacman& player) {
//	return player.getPosition_y();
//}

void FantasmaSmart::IASmart(char mapa[20][30]) {

}
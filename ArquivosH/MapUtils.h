#ifndef MAPUTILS_H
#define MAPUTILS_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../ArquivosH/Moeda.h"
#include "../ArquivosH/Pilula.h"
#include "../ArquivosH/Tijolo.h"
#include "../ArquivosH/KeyboardEvents.h"

using namespace std;

char mapa[20][31] = {
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "Xoooo|ooooooXXXXXoooooo|ooooX",
  "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
  "XoXXXoXXXXXoXXXXXoXXXXXoXXXoX",
  "XoooooooooooooooooooooooooooX",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoooooXXoooooXXXoooooXXoooooX",
  "XoXXXoXXXXXXoXXXoXXXXXXoXXXoX",
  "XoXXXoXXoooo|ooo|ooooXXoXXXoX",
  " oooooXXoXXXXXXXXXXXoXXooooo ",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoXXXoXXoooooooooooooXXoXXXoX",
  "XoXXXoXXXXXXoXXXoXXXXXXoXXXoX",
  "XoooooXXoooooXXXoooooXXoooooX",
  "XoXXXoXXoXXXXXXXXXXXoXXoXXXoX",
  "XoXXX|ooooooooooooooooo|XXXoX",
  "XoXXXoXXXXoXXXXXXXXoXXXoXXXoX",
  "XoXXXoXXXXooooooooooXXXoXXXoX",
  "Xoooo|oooooXXXXXXXXoooo|ooooX",
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
};


void criarMapa() {
	Tijolo tijoloObject;
	Moeda moedaObject;
	Pilula pilulaObject;


	int linha, coluna;
	for (linha = 0; linha < 20; linha++) {
		for (coluna = 0; coluna < 31; coluna++) {
			if (mapa[linha][coluna] == 'X') {
				tijoloObject.renderizaTijolo(linha, coluna);
			}
			else if (mapa[linha][coluna] == 'o') {
				moedaObject.renderizaMoeda(linha, coluna);
			}
			else if (mapa[linha][coluna] == '|') {
				pilulaObject.renderizaPilula(linha, coluna);
			}
			else if (mapa[linha][coluna] == ' ') {
				cout << "linha: " << linha << endl << "coluna: " << coluna << endl;
			};
		};
	};
};

void RenderizaMapa() {

	while (true)
	{
		criarMapa();
		/*pacmanFunction(mapa);*/
		al_flip_display();
	}

}

#endif // !MAPUTILS_H

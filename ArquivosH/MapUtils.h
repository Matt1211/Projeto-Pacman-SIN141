#ifndef MAPUTILS_H
#define MAPUTILS_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../ArquivosH/Moeda.h"
#include "../ArquivosH/Pilula.h"
#include "../ArquivosH/Tijolo.h"

using namespace std;
const int LINHAS = 20;
const int COLUNAS = 31;
bool teclas[255] = { false }; //Vetor de Teclas
bool EXIT = false;

char mapa[LINHAS][COLUNAS] = {
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
	for (linha = 0; linha < LINHAS; linha++) {
		for (coluna = 0; coluna < COLUNAS; coluna++) {
			if (mapa[linha][coluna] == 'X') {
				tijoloObject.renderizaTijolo(linha, coluna);
			}
			else if (mapa[linha][coluna] == 'o') {
				moedaObject.renderizaMoeda(linha, coluna);
			}
			else if (mapa[linha][coluna] == '|') {
				pilulaObject.renderizaPilula(linha, coluna);
			};
		};
	};
};

void RenderizaMapa() {
	

		criarMapa();
		al_flip_display();
}

#endif // !MAPUTILS_H

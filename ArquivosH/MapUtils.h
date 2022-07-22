#ifndef MAPUTILS_H
#define MAPUTILS_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "../ArquivosH/Moeda.h"
#include "../ArquivosH/Pilula.h"
#include "../ArquivosH/Tijolo.h"
#include "../ArquivosH/Pacman.h"
#include "../ArquivosH/Fantasma.h"

using namespace std;


// 0 = Tijolo; 1 = Moeda; 2 = Pilula

char mapa[20][30] = {
  "00000000000000000000000000000",
  "01111211111100000111111211110",
  "01000100000100000100000100010",
  "01000100000100000100000100010",
  "01111111111111111111111111110",
  "01000100100000000000100100010",
  "01111100111110001111100111110",
  "01000100000010001000000100010",
  "01000100111121112111100100010",
  "01111100100000000000100111110",
  "01000100100000000000100100010",
  "01000100111111 11111100100010",
  "01000100000010001000000100010",
  "01111100111110001111100111110",
  "01000100100000000000100100010",
  "01000211111111111111111200010",
  "01000100001000000001000100010",
  "01000100001111111111000100010",
  "01111211111000000001111211110",
  "00000000000000000000000000000",
};


void criarMapa() {
	Tijolo tijoloObject;
	Moeda moedaObject;
	Pilula pilulaObject;
	Pacman playerPacman;
	cout << playerPacman.getPosition_y() / 33 << endl;
	cout << playerPacman.getPosition_x() / 33 << endl;

	int linha, coluna;
	for (linha = 0; linha < 20; linha++) {
		for (coluna = 0; coluna < 30; coluna++) {
			if (mapa[linha][coluna] == '0') {
				tijoloObject.renderizaTijolo(linha, coluna);
			}
			else if (mapa[linha][coluna] == '1') {
				moedaObject.renderizaMoeda(linha, coluna);
			}
			else if (mapa[linha][coluna] == '2') {
				pilulaObject.renderizaPilula(linha, coluna);
			}
		}
	}
};

#endif // !MAPUTILS_H

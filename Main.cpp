#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "Tijolo.h"
#include "Pilula.h"
#include "Moeda.h"

using namespace std;

const int LINHAS = 20;
const int COLUNAS = 31;
bool EXIT = false;


int main() {
	ALLEGRO_DISPLAY* display = NULL;
	Tijolo tijolo;
	Pilula pilula;
	Moeda moeda;

	if (!al_init()) {
		cout << "Failed to initialize allegro!" << endl;
		return -1;
	}

	display = al_create_display(880, 600);
	if (!display) {
		cout << "Failed to create the display!" << endl;
		return -1;
	}

    while (!EXIT) {
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

		int row, col;
		for (row = 0; row < LINHAS; row++) {
			for (col = 0; col < COLUNAS; col++) {
				if (mapa[row][col] == 'X') {
					tijolo.drawTijolo(row, col);
				}
				else if (mapa[row][col] == 'o') {
					moeda.drawMoeda(row, col);
					//if (py / 30 == row && px / 30 == col) {
					//	mapa[row][col] = '';
					//};
				}
				else if (mapa[row][col] == '|') {
					tijolo.drawTijolo(row, col);
					
				};
			};
		};

	    al_flip_display();
		al_rest(10);
		/*EXIT = true;*/
    };


	al_destroy_display(display);
	al_uninstall_system();

	return 0;
}

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#define TIJOLO_IMG "images/tijolo.png"
#define MOEDA_IMG "images/comida.png"
#define PILULA_IMG "images/pilula.png"

using namespace std;
const int LINHAS = 20;
const int COLUNAS = 31;
bool EXIT = false;

ALLEGRO_BITMAP* tijolo = NULL;
ALLEGRO_BITMAP* moeda = NULL;
ALLEGRO_BITMAP* pilula = NULL;



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
	int row, col;
	for (row = 0; row < LINHAS; row++) {
		for (col = 0; col < COLUNAS; col++) {
			if (mapa[row][col] == 'X') {
				al_draw_bitmap(tijolo, col * 30, row * 30, 0);
			}
			else if (mapa[row][col] == 'o') {
				al_draw_bitmap(moeda, col * 30 + 8, row * 30 + 8, 0);
				//if (py / 30 == row && px / 30 == col) {
				//	mapa[row][col] = '';
				//};
			}
			else if (mapa[row][col] == '|') {
				al_draw_bitmap(pilula, col * 30 + 8, row * 30 + 6, 0);
			};
		};
	};
};

int main() {
	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		cout << "Failed to initialize allegro!" << endl;
		return -1;
	}

	al_init_image_addon();

	display = al_create_display(880, 600);
	if (!display) {
		cout << "Failed to create the display!" << endl;
		return -1;
	}

    tijolo = al_load_bitmap(TIJOLO_IMG);
	moeda = al_load_bitmap(MOEDA_IMG);
	pilula = al_load_bitmap(PILULA_IMG);


    while (!EXIT) {
        criarMapa();
	    al_flip_display();
		al_rest(10);
		/*EXIT = true;*/
    };


	al_destroy_display(display);
	al_uninstall_system();

	return 0;
}

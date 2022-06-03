#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#define TIJOLO_IMG "images/tijolo.png"
#define PILULA_IMG "images/comida.png"

using namespace std;
const int LINHAS = 20;
const int COLUNAS = 31;
bool EXIT = false;

ALLEGRO_BITMAP* tijolo = NULL;
ALLEGRO_BITMAP* pilula = NULL;



char mapa[LINHAS][COLUNAS] = {
  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
  "Xo o |o o o XXXXX o o o| o  X",
  "XoXXX XXXXX XXXXX XXXXX XXX X",
  "XoXXX XXXXX XXXXX XXXXX XXXoX",
  "Xo o o o|o o o o o o|o o o oX",
  "XoXXXoXX XXXXXXXXXXX XXoXXXoX",
  "Xo o |XXo o |XXX|o o XXo o oX",
  "XoXXXoXXXXXX XXX XXXXXXoXXXoX",
  "X XXXoXX ooo|ooo|ooo XXoXXX X",
  " o o |XX XXXXX XXXXX XX| o o ",
  "X XXXoXX XXXXXXXXXXX XXoXXX X",
  "XoXXXoXX oo |ooo|ooo XXoXXXoX",
  "X XXXoXXXXXX XXX XXXXXXoXXX X",
  "Xo o  XXo o oXXX o o XX o o X",
  "X XXXoXX XXXXXXXXXXX XXoXXX X",
  "XoXXX| o| o o o o o |o |XXXoX",
  "X XXXoXXXX XXXXXXXX XXX XXX X",
  "XoXXXoXXXX o o o o oXXX XXXoX",
  "X  o |o o  XXXXXXXX o o| o  X",
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
				al_draw_bitmap(pilula, col * 30, row * 30, 0);
				//if (py / 30 == row && px / 30 == col) {
				//	mapa[row][col] = '';
				//};
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

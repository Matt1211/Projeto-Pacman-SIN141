#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_image.h>
#define MAP_IMG "images/map.bmp"
#define PONTO_IMG "images/ponto.png"

using namespace std;

int mapa(int mod) {
	int i, j;
	int maps[24][24];
	ALLEGRO_BITMAP* ponto = NULL;

	ponto = al_load_bitmap(PONTO_IMG);
	if (!ponto) {
		cout << "Faile to load ponto image file" << endl;
		return -1;
	}

	char mp[24][24] =
	{
		"11111111111111111111111",
		"12222222222122222222221",
		"12111211112121111211121",
		"12111211112121111211121",
		"12222222222222222222221",
		"12111212111111121211121",
		"12222212222122221222221",
		"11111211110101111211111",
		"11111210000000001211111",
		"11111210111011101211111",
		"00000000111011100000000",
		"11111210111011101211111",
		"11111210111111101211111",
		"11111210000000001211111",
		"11111210111111101211111",
		"12222222222122222222221",
		"12111211112121111211121",
		"12221222222022222212221",
		"11121212111111121212111",
		"12222212222122221222221",
		"12111111112121111111121",
		"12222222222222222222221",
		"11111111111111111111111",
	};

	for (i = 0; i < 24; i++) {
		for (j = 0; j < 24; j++) {
			if (mod)maps[i][j] = mp[i][j];
			if (maps[i][j] == 2) al_draw_bitmap(ponto, 0, 0, 0);
		}
	}
}

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *map = NULL;

	if (!al_init()) {
		cout << "Failed to initialize allegro!" << endl;
		return -1;
	}

	al_init_image_addon();
	
	display = al_create_display(460, 460);

	if (!display) {
		cout << "Failed to create the display!" << endl;
		return -1;
	}

	map = al_load_bitmap(MAP_IMG);
	if (!map) {
		cout << "Faile to load map image file" << endl;
		return -1;
	}

	al_draw_bitmap(map, 0, 0, 0);
	mapa(0);

	al_flip_display();

	al_rest(5);

	al_destroy_display(display);
	al_destroy_bitmap(map);
	al_uninstall_system();
	return 0;
}

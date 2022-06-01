#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_image.h>
#define BACKGROUND_IMG "images/background.jpg"
#define TIJOLO_IMG "images/tijolo.png"

using namespace std;

int main() {
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_BITMAP* background = NULL, *tijolo = NULL;

	if (!al_init()) {
		cout << "Failed to initialize allegro!" << endl;
		return -1;
	}

	al_init_image_addon();

	display = al_create_display(640, 480);

	if (!display) {
		cout << "Failed to create the display!" << endl;
		return -1;
	}

	background = al_load_bitmap(BACKGROUND_IMG);
	if (!background) {
		cout << "Faile to load background image file" << endl;
		return -1;
	}

	tijolo = al_load_bitmap(TIJOLO_IMG);
	if (!background) {
		cout << "Faile to load tijolo image file" << endl;
		return -1;
	}


	al_draw_bitmap(background, 0, 0, 0);

	al_draw_bitmap(tijolo, 200, 200, 0);

	al_flip_display();

	al_rest(15.0);

	al_destroy_display(display);
	al_destroy_bitmap(background);
	al_uninstall_system();
	return 0;
}
#include <iostream>
#include <allegro5/allegro.h>
#include "../ArquivosH/MapUtils.h"
#include "../ArquivosH/KeyboardEvents.h"

using namespace std;

int main() {
	ALLEGRO_DISPLAY* display = NULL;

	if (!al_init()) {
		cout << "Failed to initialize allegro!" << endl;
		return -1;
	}

	display = al_create_display(1280, 720);
	if (!display) {
		cout << "Failed to create the display!" << endl;
		return -1;
	}

	al_init_image_addon();

	RenderizaMapa();

	al_destroy_display(display);
	al_uninstall_system();

	return 0;
}

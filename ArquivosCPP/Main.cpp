#include <iostream>
#include <allegro5/allegro.h>
#include "../ArquivosH/MapUtils.h"

using namespace std;

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

	RenderizaMapa();

	al_destroy_display(display);
	al_uninstall_system();

	return 0;
}

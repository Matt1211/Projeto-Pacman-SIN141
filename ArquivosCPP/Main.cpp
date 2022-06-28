#include <iostream>
#include <allegro5/allegro.h>
#include "../ArquivosH/MapUtils.h"
#include "../ArquivosH/Pacman.h"
#include "../ArquivosH/Map.h"
#include <allegro5/allegro_primitives.h>

using namespace std;

const float FPS = 30;

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
	al_install_keyboard();

	bool done = false;

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	al_start_timer(timer);

	Pacman playerPacman;

	criarMapa();

	while (!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		playerPacman.renderizaPacman();

		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {

			case ALLEGRO_KEY_DOWN:
				playerPacman.setDirection(DOWN);
				break;

			case ALLEGRO_KEY_UP:
				playerPacman.setDirection(UP);
				break;

			case ALLEGRO_KEY_RIGHT:
				playerPacman.setDirection(RIGHT);
				break;

			case ALLEGRO_KEY_LEFT:
				playerPacman.setDirection(LEFT);
				break;

			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}

		if (events.type == ALLEGRO_EVENT_TIMER) {
			cout << playerPacman.getDirection() <<endl;
			switch (playerPacman.getDirection())
			{
			case DOWN:
				playerPacman.segueAbaixo(mapa);
				break;

			case UP:
				playerPacman.segueAcima(mapa);
				break;

			case RIGHT:
				playerPacman.segueDireita(mapa);
				break;

			case LEFT:
				playerPacman.segueEsquerda(mapa);
				break;

			case STILL:
				break;
			}
		}

		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_uninstall_system();

	return 0;
}

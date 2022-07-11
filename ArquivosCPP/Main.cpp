#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

#include "../ArquivosH/MapUtils.h"
#include "../ArquivosH/Pacman.h"
#include "../ArquivosH/Map.h"
#include "../ArquivosH/Fantasma.h"

#define PACMAN_MUSIC "images/Pac_man.mp3"

using namespace std;

const float FPS = 10;

int main() {
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sample = NULL;
	ALLEGRO_SAMPLE_INSTANCE* instance = NULL;

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
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	sample = al_load_sample(PACMAN_MUSIC);

	instance = al_create_sample_instance(sample);

	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

	if (!sample) {
		printf("Audio clip sample not loaded!\n");
		return -1;
	}

	Pacman playerPacman;
	Fantasma playerFantasma;

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		criarMapa();

		al_play_sample_instance(instance);
		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

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

		playerPacman.arredondamento();

		playerPacman.renderizaPacman(
			playerPacman.getPosition_x(),
			playerPacman.getPosition_y(),
			playerPacman.getDirection()
		);

		playerFantasma.renderizaFantasma(mapa);

		/*destruirMapa();*/

		al_flip_display();
	}
	al_stop_sample_instance(instance);

	al_destroy_display(display);
	al_destroy_sample(sample);
	al_destroy_sample_instance(instance);
	//al_destroy_bitmap(tijoloBitmap);
	//al_destroy_bitmap(moedaBitmap);
	//al_destroy_bitmap(pilulaBitmap);
	//al_destroy_bitmap(pacmanBitmap);
	al_destroy_event_queue(event_queue);
	al_uninstall_system();

	return 0;
}

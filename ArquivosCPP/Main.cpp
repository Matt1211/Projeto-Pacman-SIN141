#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include "../ArquivosH/MapUtils.h"
#include "../ArquivosH/Pacman.h"
#include "../ArquivosH/Pilula.h"
#include "../ArquivosH/Map.h"
#include "../ArquivosH/Fantasma.h"
#include "../ArquivosH/FantasmaSmart.h"
#include "../ArquivosH/Collision.h"
#include "../ArquivosH/Score.h"

#define PACMAN_MUSIC "images/Pac_man.mp3"
#define FONTE_ARIAL "images/arial.ttf"

using namespace std;

const float FPS = 10;
const int SCREEN_W = 1280;
const int SCREEN_H = 720;

int main() {
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE* sample = NULL;
	ALLEGRO_SAMPLE_INSTANCE* instance = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_FONT* fonte = NULL;

	if (!al_init())
	{
		cout << "Falha ao carregar Allegro" << endl;
		return -1;
	}

	if (!al_install_keyboard())
	{
		cout << "Falha ao inicializar o teclado" << endl;
		return 0;
	}

	timer = al_create_timer(1 / FPS);
	if (!timer)
	{
		cout << "Falha ao inicializar o temporizador" << endl;
		return 0;
	}

	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}

	sample = al_load_sample(PACMAN_MUSIC);
	if (!sample) {
		printf("Audio clip sample not loaded!\n");
		return -1;
	}

	if (!al_init_image_addon())
	{
		cout << "Falha ao iniciar al_init_image_addon!" << endl;
		return 0;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		cout << "Falha ao inicializar a tela" << endl;
		al_destroy_timer(timer);
		return 0;
	}

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		cout << "Falha ao criar a fila de eventos" << endl;
		al_destroy_display(display);
		al_destroy_timer(timer);
		return 0;
	}

	al_init_image_addon();
	al_install_keyboard();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();

	fonte = al_load_font(FONTE_ARIAL, 28, 0);
	instance = al_create_sample_instance(sample);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	al_reserve_samples(1);

	bool done = false;

	Pacman playerPacman;
	Fantasma playerFantasmaAmarelo(AMARELO, 15, 15); //Amarelo
	Fantasma playerFantasmaAzul(AZUL, 12, 15); //Azul
	FantasmaSmart playerFantasmaLaranja(18, 15); //Laranja
	Fantasma playerFantasmaRosa(ROSA, 14, 15); //Rosa

	al_start_timer(timer);
	int pontos = 0, linha = 20, coluna = 30;
	bool redraw = true;

	while (!done && pontos < 308)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		al_play_sample_instance(instance);
		al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

		if (events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}

		if (events.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (events.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}

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
		else if (events.type == ALLEGRO_EVENT_TIMER) {

			redraw = true;

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


		if (redraw && al_is_event_queue_empty(event_queue)) {

			redraw = false;

			criarMapa();

			playerPacman.renderizaPacman();
			playerScore(playerPacman, pontos);

			playerFantasmaAmarelo.renderizaFantasma(mapa);
			playerFantasmaAzul.renderizaFantasma(mapa);
			playerFantasmaRosa.renderizaFantasma(mapa);
			playerFantasmaLaranja.setDirection(playerPacman.getDirection());
			playerFantasmaLaranja.renderizaFantasma(mapa, playerPacman.getPosition_x(), playerPacman.getPosition_y());

			if (Colisao(playerPacman, playerFantasmaAmarelo)
				||
				Colisao(playerPacman, playerFantasmaAzul)
				||
				Colisao(playerPacman, playerFantasmaRosa)
				||
				Colisao(playerPacman, playerFantasmaLaranja))
			{
				done = true;
			}

			al_draw_textf(fonte, al_map_rgb(255, 255, 255), 1050, 150, 0, "SCORE: %d", pontos);
			al_flip_display();

			al_clear_to_color(al_map_rgb(0, 0, 0));

		}
	}

	al_stop_sample_instance(instance);

	al_destroy_display(display);
	al_destroy_sample(sample);
	al_destroy_sample_instance(instance);
	al_destroy_event_queue(event_queue);
	al_destroy_font(fonte);
	al_destroy_timer(timer);
	al_uninstall_system();

	return 0;
}

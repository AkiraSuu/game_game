#include <stdio.h>
#include <SDL.h>

#include "game.h"
#include "window.h"
#include "texture.h"

static Uint32 fps = 30;
static int _game_handle_event();
static int _game_draw();
static struct texture *t1;
static struct texture *t2;

int game_init()
{
	t1 = texture_load("data/s_s.png");
	t2 = texture_load("data/tom1.png");
	return 0;
}

int game_loop()
{
	Uint32 ticks_per_second = 1000/fps;
	Uint32 next_ticks = SDL_GetTicks() + ticks_per_second;
	Uint32 now_ticks;
	while(1){
		//1,
		now_ticks = SDL_GetTicks();
		if (now_ticks < next_ticks) {
			SDL_Delay(next_ticks - now_ticks);
		}
		next_ticks += ticks_per_second;
		if (_game_handle_event() == 1) {
			return 1;
		}
		if (_game_draw() < 0)  {
			printf("_game_draw_error");
			return -1;
		}
		//2,
		//3,
	}
	return 0;
}

void game_close()
{
	texture_clean(t1);
	texture_clean(t2);
}

static int _game_handle_event()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return 1;
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				printf(
			}
		}
	}
	return 0;
}
static int _game_draw()
{
	if (window_paste_texture(t1, 0, 0) < 0) {
		return -1;
	}

	if (window_paste_texture(t2, 200, 200) < 0) {
		return -1;
	}

	window_update();

	return 0;
}
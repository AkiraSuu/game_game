#include <SDL.h>
#include <stdio.h>
#include "window.h"

static SDL_Window *_window;
static SDL_Renderer *_window_renderer;

int window_init(char *label, int width, int height)
{
	_window = SDL_CreateWindow(label, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, 0);
	if (_window == NULL) {
		printf("window_error");
		return -1;
	}
	_window_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_TARGETTEXTURE);
	if (_window_renderer == NULL) {
		printf("_window_renderer_error");
		SDL_DestroyWindow(_window);
		return -1;
	}
	return 0;
}

void window_close()
{
	SDL_DestroyRenderer(_window_renderer);
	SDL_DestroyWindow(_window);
}

SDL_Renderer *window_get_renderer()
{
	return _window_renderer;
}

void window_update()
{
	SDL_RenderPresent(_window_renderer);
}

int window_paste_texture(struct texture *t, int x, int y)
{
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = t->width;
	dst.h = t->height;

	if (SDL_RenderCopy(_window_renderer, t->texture, NULL, &dst) < 0) {
		printf("SDL_RenderCopy_error");
		return -1;
	}
	return 0;
}
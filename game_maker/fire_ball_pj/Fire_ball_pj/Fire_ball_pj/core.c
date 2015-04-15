
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "core.h"

int core_init()
{
	int flag_img = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted_img;
	int flag_mix = MIX_INIT_MP3;
	int initted_mix;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("error");
		return -1;
	}

	initted_img = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if ((flag_img & initted_img) != flag_img) {
		printf("error img");
		SDL_Quit();
		return -1;
	}

	if (TTF_Init() < 0) {
		printf("error ttf");
		IMG_Quit();
		SDL_Quit();
		return -1;
	}

	initted_mix = Mix_Init(MIX_INIT_MP3);
	if ((flag_mix & initted_mix) != flag_mix) {
		printf("error mix");
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();
		return -1;
	}

	return 0;
}

void core_deinit()
{
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
#include <stdio.h>

#include "SDL_image.h"
#include "texture.h"
#include "window.h"

struct texture * texture_load(const char *path)
{
	struct texture *tmp;
	SDL_Texture *t;
	SDL_Surface *s;
	s = IMG_Load(path);
	if (s == NULL) {
		printf("IMG_Load_error");
		return NULL;
	}
	t = SDL_CreateTextureFromSurface(window_get_renderer(), s);
	if (t == NULL) {
		printf("SDL_CreateTextureFromSurface_errer");
		SDL_FreeSurface(s);
		return NULL;
	}
	SDL_FreeSurface(s);
	
	tmp = (struct texture *)malloc(sizeof(struct texture));
	if (tmp == NULL) {
		printf("Malloc failed");
		SDL_DestroyTexture(t);
		return NULL;
	}
	
	tmp->texture = t;
	if (SDL_QueryTexture(tmp->texture, NULL, NULL, &tmp->width, &tmp->height) < 0) {
		printf("SDL_QueryTexture_get_error");
		texture_clean(tmp);
		return NULL;
	}
	return tmp;
}

void texture_clean(struct texture *t)
{
	SDL_DestroyTexture(t->texture);
	free(t);
}

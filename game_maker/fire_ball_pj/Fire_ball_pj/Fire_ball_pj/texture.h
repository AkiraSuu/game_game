#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL.h>

struct texture {
	SDL_Texture *texture;
	int width;
	int height;
};

struct texture * texture_load(const char *path);
void texture_clean(struct texture *t);


#endif

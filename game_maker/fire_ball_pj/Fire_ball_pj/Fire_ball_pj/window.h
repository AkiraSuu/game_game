#ifndef _WINDOW_H
#define _WINDOW_H

#include <SDL.h>

#include "texture.h"

int window_init(char *label, int width, int height);
void window_close();
SDL_Renderer *window_get_renderer();
void window_update();
int window_paste_texture(struct texture *t, int x, int y);

#endif

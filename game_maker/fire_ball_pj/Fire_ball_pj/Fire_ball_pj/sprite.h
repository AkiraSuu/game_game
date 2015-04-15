#ifndef _SPRITE_H
#define _SPRITE_H

struct sprite {
	struct texture *texture;
	int x;
	int y;
};

struct sprite * sprite_load(const char *path);
void sprite_clean(struct sprite *s);

#endif

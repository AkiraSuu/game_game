#include <stdlib.h>
#include <stdio.h>

#include "sprite.h"
#include "texture.h"

struct sprite * sprite_load(const char *path)
{
	struct sprite *tmp = (struct sprite *)malloc(sizeof(struct sprite));
	if (tmp == NULL) {
		printf("tmp_malloc_error");
		return NULL;
	}
	tmp->texture = texture_load(path);
	if (tmp->texture == NULL) {
	
	}
}

void sprite_clean(struct sprite *s)
{
}
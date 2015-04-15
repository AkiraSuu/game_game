

//Using SDL and standard IO
#include <stdio.h>
#include <stdlib.h>
#include "core.h"
#include "window.h"
#include "game.h"

int main(int argc, char* argv[])
{
	if (core_init() < 0) {
		printf("error");
		exit(1);
	}

	if (window_init("fire_ball", 800, 600) < 0) {
		printf("error");
		core_deinit();
		exit(1);
	}

	game_init();
	game_loop();
	game_close();

	window_close();
	core_deinit();
	return 0;
}


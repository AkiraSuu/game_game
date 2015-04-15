#include "../stdafx.h"
#include "../include/CSDL_Setup.h"

#include <iostream>
using namespace std;

CSDL_Setup::CSDL_Setup(bool* quit,int ScreenWidth,int ScreenHeight)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cerr << "SDL_Init failed." << endl;
		exit(1);
	}
    //ctor
    window = SDL_CreateWindow("hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
		cerr << "window couldn`t be created" << endl;
		*quit=true;
	}

	renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

}

CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
    //dtor
}


SDL_Renderer* CSDL_Setup::GetRenderer(){//9:22 overby
return renderer;
}

SDL_Event CSDL_Setup::GetMainEvent(){
	return mainEvent;
}

void CSDL_Setup::Begin(){

	SDL_PollEvent(&mainEvent);
	SDL_RenderClear(renderer);
}

void CSDL_Setup::End(){
    SDL_RenderPresent(renderer);
}

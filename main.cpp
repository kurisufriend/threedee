#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "SDL.h"

#include "demo/demo.h"

int main(int argc, char** argv)
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("threedee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, NULL);
	SETRENDER_WHITE;
	SDL_Event eventHandler;

	//global::entList.push_back(&square(200, 200, 50));
	global::entList3D.push_back(&cube(1, 1, 50, 50));

	while (global::running)
	{
		callbacks::handleCallbacks(&eventHandler);

		SETRENDER_BLACK;
		SDL_RenderClear(renderer);
		SETRENDER_WHITE;

		game::run(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(1);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
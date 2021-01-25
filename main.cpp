#include <Windows.h>
#include <stdio.h>
#include "SDL.h"

#include "stuff/objects/vector2.h"
#include "stuff/objects/vector3.h"

#include "stuff/globals/globals.h"
#include "stuff/callbacks/callbacks.h"
#include "stuff/objects/square.h"

int main(int argc, char** argv)
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("threedee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	SDL_Event eventHandler;

	global::entList.push_back(square(200, 200, 50));

	while (global::running)
	{
		callbacks::handleCallbacks(&eventHandler);

		global::entList.run(surface);

		SDL_UpdateWindowSurface(window);
		SDL_Delay(1);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
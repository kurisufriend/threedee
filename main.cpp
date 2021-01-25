#include <Windows.h>
#include <stdio.h>
#include "SDL.h"

#include "stuff/objects/vector2.h"
#include "stuff/objects/vector.h"

#include "stuff/globals/globals.h"
#include "stuff/callbacks/callbacks.h"

int main(int argc, char** argv)
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("threedee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	SDL_Event eventHandler;

	while (global::running)
	{
		callbacks::handleCallbacks(&eventHandler);
		SDL_Rect cursor{ global::mousePos.x, global::mousePos.y, 5, 5 };
		SDL_FillRect(surface, &cursor, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(window);
		SDL_Delay(1);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "SDL.h"

#include "stuff/objects/vector2.h"
#include "stuff/objects/vector3.h"
#include "stuff/objects/ray2D.h"

#include "stuff/globals/globals.h"
#include "stuff/callbacks/callbacks.h"
#include "stuff/objects/square.h"

int main(int argc, char** argv)
{
	SDL_Window* window = nullptr;
	SDL_Surface* surface = nullptr;
	SDL_Renderer* renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("threedee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, NULL);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Event eventHandler;

	global::entList.push_back(square(200, 200, 50));

	//global::entList3D.push_back(cube(200, 200, 100, 50));

	while (global::running)
	{
		callbacks::handleCallbacks(&eventHandler);

		ray2D ray = ray2D::trace(vector2(0, 201), vector2(.01, 0));
		ray2D ray2 = ray2D::trace(vector2(201, 0), vector2(0, .01));

		SDL_RenderDrawLine(renderer, ray.start.x, ray.start.y, ray.end.x, ray.end.y);
		SDL_RenderDrawLine(renderer, ray2.start.x, ray2.start.y, ray2.end.x, ray2.end.y);


		global::entList.run(renderer);
		global::entList3D.run(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(1);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
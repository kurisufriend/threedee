#include <Windows.h>
#include <stdio.h>
#include "SDL.h"

struct Vector2
{ 
	float x, y;
	Vector2()
	{
		this->x = 0.f;
		this->y = 0.f;
	}
	Vector2(float x_, float y_)
	{
		this->x = x_;
		this->y = y_;
	}
};

int main(int argc, char** argv)
{
	bool running = true;
	Vector2 mousePos;

	SDL_Window* window = nullptr;;
	SDL_Surface* surface = nullptr;;

	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("threedee", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);

	SDL_Event eventHandler;

	while (running)
	{
		while (SDL_PollEvent(&eventHandler))
		{
			switch (eventHandler.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEMOTION:
				mousePos = Vector2(eventHandler.motion.x, eventHandler.motion.y);
				break;
			}
		}
		SDL_Rect cursor;
		cursor.x = mousePos.x;
		cursor.y = mousePos.y;
		cursor.w = 5;
		cursor.h = 5;
		SDL_FillRect(surface, &cursor, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

		SDL_UpdateWindowSurface(window);
		SDL_Delay(1);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
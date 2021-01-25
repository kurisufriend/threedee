#pragma once
#include "SDL.h"

struct square
{
	SDL_Rect rect;
	square()
	{
		rect.x = 0;
		rect.y = 0;
		rect.w = 0;
		rect.h = 0;
	}
	square(int x_, int y_, int w_, int h_)
	{
		rect.x = x_;
		rect.y = y_;
		rect.w = w_;
		rect.h = h_;
	}
	void run(SDL_Surface* surface)
	{
		SDL_FillRect(surface, &this->rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	}
};
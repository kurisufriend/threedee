#pragma once
#include "SDL.h"

#include "vector2.h"
/*
squares are the basic 2D entity
*/
struct square : public vector2
{
	int radius;
	square()
	{
		this->x = 0;
		this->y = 0;
		this->radius = 0;
	}
	square(int x_, int y_, int radius_)
	{
		this->x = x_;
		this->y = y_;
		this->radius = radius_;
	}
	void run(SDL_Surface* surface)
	{
		SDL_Rect rect{ this->x, this->y, this->radius, this->radius };
		SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	}
};
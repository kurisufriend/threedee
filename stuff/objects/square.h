#pragma once
#include "SDL.h"

#include "vector2.h"
/*
squares are the basic 2D entity
*/
struct square : public vector2
{
	int radius;
	square() : vector2()
	{
		this->radius = 0;
	}
	square(float x_, float y_, int radius_) : vector2(x_, y_)
	{
		this->radius = radius_;
	}
	void run(SDL_Surface* surface)
	{
		SDL_Rect rect{ this->x, this->y, this->radius, this->radius };
		SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
	}
};
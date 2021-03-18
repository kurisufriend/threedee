#pragma once
#include "square.h"
/*
cubes are the basic 3D entity
*/
struct cube : public square
{
	float z;
	cube() : square()
	{
		this->z = 0;
	}
	cube(float x_, float y_, float z_, int radius_) : square(x_, y_, radius_)
	{
		this->z = z_;
	}
	void run(SDL_Renderer* renderer)
	{
		SDL_Rect rect{ this->x, this->y, this->radius, this->radius};
		//SDL_RenderFillRect(renderer, &rect);
	}
};
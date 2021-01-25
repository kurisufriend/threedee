#pragma once
#include <vector>
#include "SDL.h"

#include "square.h"
/*
entityList2D is the 2D entity container class
*/
class entityList2D : public std::vector<square>
{
public:
	void run(SDL_Surface* surface)
	{
		for (square entity : *this)
		{
			entity.run(surface);
		}
	}
};
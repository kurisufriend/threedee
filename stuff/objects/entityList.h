#pragma once
#include <vector>
#include "SDL.h"

#include "square.h"

class entityList : public std::vector<square>
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
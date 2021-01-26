#pragma once
#include <vector>
#include "SDL.h"

#include "cube.h"
/*
entityList3D is the 3D entity container class
*/
class entityList3D : public std::vector<cube>
{
public:
	void run(SDL_Renderer* renderer)
	{
		for (cube entity : *this)
		{
			entity.run(renderer);
		}
	}
};
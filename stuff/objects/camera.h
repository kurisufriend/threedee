#pragma once
#include "vector3.h"
#include "SDL.h"
#include <iostream>
struct camera
{
	vector3 position;
	vector3 rotation;
	camera(vector3 position_, vector3 rotation_)
	{
		this->position = position_;
		this->rotation = rotation_;
	}
	void run(SDL_Renderer* renderer)
	{
		//ray3D ray = ray3D::trace(vector3(0, 0, -10), vector3(0, 0, 1));
		//std::cout << ray.dist << std::endl;
	}
};
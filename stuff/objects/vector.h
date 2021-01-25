#pragma once
#include "vector2.h"
/*
vectors extend vector2s and hold 3D cartesian coordinates
*/
struct vector : public vector2
{
	float z;
	vector()
	{
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}
	vector(float x_, float y_, float z_)
	{
		this->x = x_;
		this->y = y_;
		this->z = z_;
	}
};
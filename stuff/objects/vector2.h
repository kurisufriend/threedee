#pragma once
#include <math.h>
/*
vector2s hold 2D cartesian coordinates
*/
struct vector2
{
	float x, y;
	vector2()
	{
		this->x = 0.f;
		this->y = 0.f;
	}
	vector2(float x_, float y_)
	{
		this->x = x_;
		this->y = y_;
	}
	float length()
	{
		return sqrtf((x * x) + (y * y));
	}
	float distance(vector2& other)
	{
		vector2 dist = vector2(this->x - other.x, this->y - other.y);
		return dist.length();
	}
};
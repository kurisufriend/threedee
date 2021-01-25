#pragma once
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
};
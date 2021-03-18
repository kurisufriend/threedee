#pragma once
#include "vector2.h"
/*
vector3s extend vector2s and hold 3D cartesian coordinates
*/
struct vector3 : public vector2
{
	float z;
	vector3()
	{
		this->x = 0.f;
		this->y = 0.f;
		this->z = 0.f;
	}
	vector3(float x_, float y_, float z_)
	{
		this->x = x_;
		this->y = y_;
		this->z = z_;
	}
	float length()
	{
		return sqrtf((x * x) + (y * y) + (z * z));
	}
	float distance(vector3& other)
	{
		vector3 dist = vector3(this->x - other.x, this->y - other.y, this->z - other.z);
		return dist.length();
	}
};
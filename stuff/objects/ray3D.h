#pragma once
#include <numeric>
#include "../globals/globals.h"

#include "vector3.h"
#include "cube.h"

struct ray3D
{
	vector3 start;
	vector3 end;
	float dist;
	cube* hitEnt;
	static ray3D trace(vector3 start, vector3 direction)
	{
		ray3D ray{ start, start, -1 };
		vector3 point = start;
		bool hit = false;
		while (!hit)
		{
			for (int i = 0; i < global::entList3D.size(); i++)
			{
				cube* object = global::entList3D.at(i);
				if (inCube(point, vector3(object->x, object->y, object->z), vector3(object->x + object->radius, object->y + object->radius, object->z + object->radius)) || ray.dist > 500)
				{
					ray.start = start;
					ray.end = point;
					ray.dist = start.distance(point);
					ray.hitEnt = object;
					hit = true;
					break;
				}
			}
			ray.dist = start.distance(point);
			point.x += direction.x;
			point.y += direction.y;
			point.z += direction.z;
		}
		return ray;
	}
	//temp
	static bool inCube(vector3 point, vector3 a, vector3 b)
	{
		return (point.x > a.x && point.y > a.y && point.x < b.x && point.y < b.y && point.z > a.z && point.z < b.z);
	}
};
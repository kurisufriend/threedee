#pragma once
#include "../globals/globals.h"

#include "vector2.h"

//temp
bool inRect(vector2 point, vector2 a, vector2 b)
{
	return (point.x > a.x && point.y > a.y && point.x < b.x && point.y < b.y);
}

struct ray2D
{
	vector2 start;
	vector2 end;
	float dist;
	static ray2D trace(vector2 start, vector2 direction)
	{
		ray2D ray { start, start, 19 };
		vector2 point = start;
		bool hit = false;
		while (!hit)
		{
			for (square object : global::entList)
			{
				if (inRect(point, vector2(object.x - (object.radius / 2), object.y - (object.radius / 2)), vector2(object.x + (object.radius / 2), object.y + (object.radius / 2))))
				{
					ray.start = start;
					ray.end = point;
					ray.dist = 19;
					hit = true;
					break;
				}
			}
			point.x += direction.x;
			point.y += direction.y;
		}
		return ray;
	}
};
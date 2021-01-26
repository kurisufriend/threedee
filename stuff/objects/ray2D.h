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
		ray2D ray { start, start, -1 };
		vector2 point = start;
		bool hit = false;
		while (!hit)
		{
			for (square object : global::entList)
			{
				if (inRect(point, vector2(object.x, object.y), vector2(object.x + object.radius, object.y + object.radius)))
				{
					ray.start = start;
					ray.end = point;
					ray.dist = start.distance(point);
					hit = true;
					break;
				}
			}
			ray.dist = start.distance(point);
			if (ray.dist > 1500)
			{
				ray.dist = -1;
				break;
			}
			point.x += direction.x;
			point.y += direction.y;
		}
		return ray;
	}
};
#include "demo.h"

void game::run(SDL_Renderer* renderer)
{
	for (int i = 0; i < 360; i += 1)
	{
		float x = 1 * sinf(i);
		float y = 1 * cosf(i);
		ray2D ray2 = ray2D::trace(vector2(300, 300), vector2(x, y));

		SDL_RenderDrawLine(renderer, ray2.start.x, ray2.start.y, ray2.end.x, ray2.end.y);
	}
	global::entList.at(0)->x = global::mousePos.x;
	global::entList.at(0)->y = global::mousePos.y;
	global::entList.run(renderer);
	global::entList3D.run(renderer);
}
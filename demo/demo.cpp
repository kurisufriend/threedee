#include "demo.h"

void game::run(SDL_Renderer* renderer)
{
	ray2D ray = ray2D::trace(vector2(0, 201), vector2(1, 0));
	ray2D ray2 = ray2D::trace(vector2(201, 0), vector2(0, 1));
	SDL_RenderDrawLine(renderer, ray.start.x, ray.start.y, ray.end.x, ray.end.y);
	SDL_RenderDrawLine(renderer, ray2.start.x, ray2.start.y, ray2.end.x, ray2.end.y);
	std::cout << global::entList.at(0) << std::endl;
	if (ray.hitEnt)
		std::cout << std::hex << ray.hitEnt << std::endl;

	//demo rays with moving object
	global::entList.at(0)->x = global::mousePos.x;
	global::entList.at(0)->y = global::mousePos.y;

	global::entList.run(renderer);
	global::entList3D.run(renderer);
}
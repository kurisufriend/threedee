#include "demo.h"

void game::run(SDL_Renderer* renderer)
{/*
	for (int i = 0; i < 360; i += 1)
	{
		float x = 1 * sinf(i);
		float y = 1 * cosf(i);
		ray2D ray2 = ray2D::trace(vector2(300, 300), vector2(x, y));

		SDL_RenderDrawLine(renderer, ray2.start.x, ray2.start.y, ray2.end.x, ray2.end.y);
	}
	global::entList.at(0)->x = global::mousePos.x;
	global::entList.at(0)->y = global::mousePos.y;
	global::entList.run(renderer);*/
	//global::cam.run(renderer);
	static float pitch, yaw;
	for (int y = 1; y < 250; y += 1)
	{
		for (int x = 1; x < 250; x += 1)
		{
			ray3D ray1 = ray3D::trace(vector3(x, y, 0), vector3(yaw, pitch, 1));
			if (ray1.dist < 500)
			{
				SDL_SetRenderDrawColor(renderer, 255 - ray1.dist, 255 - ray1.dist, 255 - ray1.dist, 255);
				SDL_RenderDrawPoint(renderer, x * 2, y * 2);
				SETRENDER_WHITE;
			}
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
		pitch += 1;
	if (GetAsyncKeyState(VK_UP))
		pitch -= 1;
	if (GetAsyncKeyState(VK_LEFT))
		yaw -= 1;
	if (GetAsyncKeyState(VK_RIGHT))
		yaw += 1;
	std::cout << global::entList3D.at(0)->x << global::entList3D.at(0)->y << std::endl;
	global::entList3D.run(renderer);
}
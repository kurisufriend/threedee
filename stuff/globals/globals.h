#pragma once
#include "../objects/vector3.h"
#include "../objects/camera.h"
#include "../objects/entityList2D.h"
#include "../objects/entityList3D.h"
namespace global
{
	extern bool running;
	extern vector2 mousePos;
	extern entityList2D entList;
	extern entityList3D entList3D;
	extern camera cam;
}
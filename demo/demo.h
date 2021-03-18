#pragma once
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "SDL.h"

#include "../stuff/objects/vector2.h"
#include "../stuff/objects/vector3.h"
#include "../stuff/objects/ray2D.h"
#include "../stuff/objects/ray3D.h"
#include "../stuff/objects/camera.h"

#include "../stuff/globals/globals.h"
#include "../stuff/callbacks/callbacks.h"
#include "../stuff/objects/square.h"
#include "../stuff/objects/argb.h"

namespace game
{
	void run(SDL_Renderer* renderer);
}
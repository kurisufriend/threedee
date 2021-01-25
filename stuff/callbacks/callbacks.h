#pragma once
#include <iostream>
#include "SDL.h"

#include "../globals/globals.h"

namespace callbacks
{
	inline void mouseMotion(SDL_Event* eventResponse)
	{
		global::mousePos = vector2(eventResponse->motion.x, eventResponse->motion.y);
	}
	inline void quit(SDL_Event* eventResponse)
	{
		global::running = false;
	}
	void handleCallbacks(SDL_Event* eventHandler);
}
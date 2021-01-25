#include "callbacks.h"

void callbacks::handleCallbacks(SDL_Event* eventHandler)
{
	while (SDL_PollEvent(eventHandler))
	{
		switch (eventHandler->type)
		{
		case SDL_QUIT:
			global::running = false;
			break;
		case SDL_MOUSEMOTION:
			callbacks::mouseMotion(eventHandler);
			break;
		}
	}
}
#pragma once
#include <Windows.h>
#include "SDL.h"
struct argb
{
	BYTE a, r, g, b;
	argb(BYTE a_, BYTE r_, BYTE g_, BYTE b_)
	{
		a = a_;
		r = r_;
		g = g_;
		b = b_;
	}
};

#define WHITE argb(255, 255, 255, 255)
#define RED argb(255, 255, 0, 0)
#define BLUE argb(255, 0, 0, 255)
#define GREEN argb(255, 0, 255, 0)

#define SETRENDER_WHITE SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255)
#define SETRENDER_BLACK SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0)
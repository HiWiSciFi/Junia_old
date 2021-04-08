#pragma once
#include "SDL.h"

class Window
{
private:
	SDL_Window* window = NULL;
	SDL_Surface* surface = NULL;
public:
	*Window();
	~Window();
	int create(char* title);
	void destroy();
};
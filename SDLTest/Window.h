#pragma once
#include "SDL.h"
#include "Math\Vectors\Vector2i.h"

class Window
{
private:
	SDL_Window* window;
	SDL_Surface* surface;
public:
	Window();
	~Window();
	void create(const char* title, GBM::Vector2i size);
	void create(const char* title, GBM::Vector2i position, GBM::Vector2i size);
	void destroy();

	GBM::Vector2i getSize() const;
	void setSize(const GBM::Vector2i size);
};
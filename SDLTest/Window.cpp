#include "Window.h"
#include <stdio.h>

Window::Window()
{
	this->window = NULL;
	this->surface = NULL;
}

Window::~Window()
{
	this->destroy();
}

void Window::create(const char* title, GBM::Vector2i size)
{
	this->create(title, GBM::Vector2i(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), size);
}

void Window::create(const char* title, GBM::Vector2i position, GBM::Vector2i size)
{
	// create window
	window = SDL_CreateWindow(title, position.x, position.y, 100, 100, SDL_WINDOW_SHOWN);
	this->setSize(size);

	// check for successful window creation
	if (this->window == NULL) {
		// throw error and exit application
		throw "SDL Window could not be created! SDL_Error: %s\n", SDL_GetError();
		return;
	}

	// get window surface
	this->surface = SDL_GetWindowSurface(this->window);

	// fill the surface with white
	SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 0xFF, 0xFF, 0xFF));

	// update surface
	SDL_UpdateWindowSurface(this->window);
}

void Window::destroy()
{
	SDL_DestroyWindow(this->window);
}

GBM::Vector2i Window::getSize() const
{
	GBM::Vector2i retv;
	SDL_GetWindowSize(this->window, &retv.x, &retv.y);
	return retv;
}

void Window::setSize(const GBM::Vector2i size)
{
	if (size.x <= 0 || size.y <= 0) {
		throw "Window too small! Window size must be greater than 0 on each axis!";
		return;
	}
	SDL_SetWindowSize(this->window, size.x, size.y);
	this->size = size;
}
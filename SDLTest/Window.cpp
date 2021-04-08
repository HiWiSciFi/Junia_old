#include "Window.h"

Window::Window()
{
}

Window::~Window()
{
}

int Window::create(char* title)
{
	// create window
	window = SDL_CreateWindow("Window title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	// check for successful window creation
	if (window == NULL) {
		// throw error and exit application
		printf("SDL Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return ERRORCODE::SDL_API;
	}

	// get window surface
	screenSurface = SDL_GetWindowSurface(window);

	// fill the surface with white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	// update surface
	SDL_UpdateWindowSurface(window);

	return 0;
}

void Window::destroy()
{
	SDL_DestroyWindow(window);
}

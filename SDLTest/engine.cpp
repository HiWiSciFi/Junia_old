#include "SDL.h"
#include <stdio.h>
#include "ErrorCodes.h"
#include "Window.h"

namespace engine
{
	Window window;

	// initialize the engine
	int init()
	{
		// init SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			// throw error and exit application
			printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
			return ERRORCODE::SDL_API;
		}

		window = new Window();


		return 0;
	}

	// quit the engine
	void quit()
	{
		// destroy window
		window.destroy();

		// quit SDL
		SDL_Quit();
	}
}
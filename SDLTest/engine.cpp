#include "SDL.h"
#include "Window.h"

namespace engine
{
	Window window;

	// initialize the engine
	void init()
	{
		// init SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			// throw error and exit application
			throw "SDL could not be initialized! SDL_Error:\n%s\n", SDL_GetError();
			return;
		}

		window = Window();
		
		// temp code
		window.create("Test title", GBM::Vector2i(640, 480));
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
#include "SDL.h"
#include "Window.h"

namespace engine
{
	Window window;

	// initialize the engine
	void init()
	{
		// init SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			// throw error and exit application
			throw "SDL could not be initialized! SDL_Error:\n%s\n", SDL_GetError();
			return;
		}

		window = Window();
		
		// temp code
		window.create("Test title", GBM::Vector2i(640, 480));

		bool quit = false;
		while (!quit) {
			SDL_Event e;
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}
		}
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
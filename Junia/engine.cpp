#include "SDL.h"
#include "SDL_image.h"
#include "Window.h"

namespace Junia {
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

			// init SDL_image
			int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				throw "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError();
			}

			// temp code
			window.create("Junia Window", Junia::Vector2<int>(640, 480));

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

			// quit SDL_image
			IMG_Quit();

			// quit SDL
			SDL_Quit();
		}
	}
}
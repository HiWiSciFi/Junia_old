#ifndef JUNIA_ENGINE_H_
#define JUNIA_ENGINE_H_

#include "Window.h"

namespace Junia {
	class Engine
	{
	private:
		/// @brief the standard window for general purpose rendering
		Window window;
		/// @brief if the game loop is running
		bool running = false;
		/// @brief the function containing the game loop
		/// @return the exit code of the application
		int GameLoop();

	public:
		/// @brief initialize the engine and libraries
		Engine();
		~Engine();

		/// @brief calls initialization function and loops over the game loop
		/// @return the exit code of the application
		int RunGameLoop();
	};
}

#endif
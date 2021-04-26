#ifndef JUNIA_ENGINE_H_
#define JUNIA_ENGINE_H_

#include "Window.h"
#include <functional>

namespace Junia {
	class Engine
	{
	private:
		/// @brief if the game loop is running
		bool running = false;
		/// @brief the function containing the game loop
		/// @param initFunc a callback function for initialization (returns 0 if everything went well)
		/// @param loopFunc a callback function to be called on every iteration (returns 0 if everything went well)
		/// @return the exit code of the application
		int GameLoop(std::function<int()> initFunc, std::function<int()> loopFunc);

	public:
		/// @brief initialize the engine and libraries
		Engine();
		~Engine();

		/// @brief calls initialization function and loops over the game loop
		/// @param initFunc a callback function for initialization (returns 0 if everything went well)
		/// @param loopFunc a callback function to be called on every iteration (returns 0 if everything went well)
		/// @return the exit code of the application
		int RunGameLoop(std::function<int()> initFunc, std::function<int()> loopFunc);
	};
}

#endif
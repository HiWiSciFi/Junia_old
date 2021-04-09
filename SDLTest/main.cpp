#include "SDL.h"
#include "engine.h"
#include <exception>
#include <stdio.h>

int main(int argc, char* argv[])
{
	try {
		engine::init();
		SDL_Delay(2000);
		engine::quit();
	}
	catch (std::exception e) {
		printf("There has been a fatal error during the execution of the program:\n%s\n", e.what());
		return 1;
	}

	return 0;
}
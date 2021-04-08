#include "SDL.h"
#include "engine.h"

int main(int argc, char* argv[])
{
	if (int e = engine::init() != 0) return e;

	SDL_Delay(2000);

	engine::quit();

	return 0;
}
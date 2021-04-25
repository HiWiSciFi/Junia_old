#include "junia/engine.h"

int main(int argc, char* argv[])
{
	Junia::Engine engine;
	int exitCode = engine.RunGameLoop();
	return exitCode;
}
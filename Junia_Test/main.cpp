#include <Junia/Engine.h>

int initialize() {
	return 0;
}

int loop() {
	return 0;
}

int main(int argc, char* argv[])
{
    Junia::Engine engine;
    int exitCode = engine.RunGameLoop(&initialize, &loop);
    return exitCode;
}
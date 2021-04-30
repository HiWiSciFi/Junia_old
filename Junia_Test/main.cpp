#include <Junia/Junia.h>
#include <iostream>

int initialize() {
	return 0;
}

int loop() {
	return 0;
}

int main(int argc, char* argv[])
{
    // intitialize engine and window
    Junia::Engine engine;
    Junia::Window window;
    window.create("Junia Window", JM::Vector2<int>(640, 480));

    // run game
    int exitCode = engine.RunGameLoop(&initialize, &loop);

    // exit
    return exitCode;
}
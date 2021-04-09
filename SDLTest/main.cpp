#include "SDL.h"
#include "engine.h"
#include <exception>
#include <stdio.h>

#include <iostream>
#include "math\math.h"

int main(int argc, char* argv[])
{
	GBM::iMatrix matrix = GBM::iMatrix(2, 2);
	matrix[0][0] = 1;
	matrix[1][0] = 2;
	matrix[0][1] = 3;
	matrix[1][1] = 4;

	std::cout <<
		"[" << matrix[0][0] << "," << matrix[1][0] << "," << std::endl <<
		" " << matrix[0][1] << "," << matrix[1][1] << "]" << std::endl;

	matrix -= matrix * 2;

	std::cout <<
		"[" << matrix[0][0] << "," << matrix[1][0] << "," << std::endl <<
		" " << matrix[0][1] << "," << matrix[1][1] << "]" << std::endl;

	try {
		engine::init();
		SDL_Delay(1000);
		engine::quit();
	}
	catch (std::exception e) {
		printf("There has been a fatal error during the execution of the program:\n%s\n", e.what());
		return 1;
	}

	return 0;
}
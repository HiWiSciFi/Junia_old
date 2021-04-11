#include "SDL.h"
#include "engine.h"
#include <exception>
#include <stdio.h>

#include <iostream>
#include "math\math.h"

int main(int argc, char* argv[])
{
	GBM::iMatrix m1 = GBM::iMatrix(3, 3);
	m1(0, 0) = 2;
	m1(0, 1) = 3;
	m1(0, 2) = 5;
	m1(1, 0) = 2;
	m1(1, 1) = 1;
	m1(1, 2) = 1;
	m1(2, 0) = 5;
	m1(2, 1) = 3;
	m1(2, 2) = 7;

	GBM::iMatrix m2 = GBM::iMatrix(m1);

	std::cout <<
		"[" << m2(0, 0) << "," << m2(0, 1) << "," << m2(0, 2) << "," << std::endl <<
		" " << m2(1, 0) << "," << m2(1, 1) << "," << m2(1, 2) << "," << std::endl <<
		" " << m2(2, 0) << "," << m2(2, 1) << "," << m2(2, 2) << "]" << std::endl;

	m2 *= m1.setAsIdentityMatrix();

	std::cout <<
		"[" << m1(0, 0) << "," << m1(0, 1) << "," << m1(0, 2) << "," << std::endl <<
		" " << m1(1, 0) << "," << m1(1, 1) << "," << m1(1, 2) << "," << std::endl <<
		" " << m1(2, 0) << "," << m1(2, 1) << "," << m1(2, 2) << "]" << std::endl;

	std::cout <<
		"[" << m2(0, 0) << "," << m2(0, 1) << "," << m2(0, 2) << "," << std::endl <<
		" " << m2(1, 0) << "," << m2(1, 1) << "," << m2(1, 2) << "," << std::endl <<
		" " << m2(2, 0) << "," << m2(2, 1) << "," << m2(2, 2) << "]" << std::endl;
	
	/*try {
		engine::init();
		SDL_Delay(1000);
		engine::quit();
	}
	catch (std::exception e) {
		printf("There has been a fatal error during the execution of the program:\n%s\n", e.what());
		return 1;
	}*/

	return 0;
}
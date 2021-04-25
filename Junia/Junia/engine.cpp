#include "engine.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

void Junia::Engine::GameLoop()
{
	this->running = true;
	SDL_Event sdlEvent;
	while (this->running) {
		try {
			while (SDL_PollEvent(&sdlEvent) != 0) {
				if (sdlEvent.type == SDL_QUIT) {
					this->running = false;
				}
			}
		}
		catch (const char* e) {
			printf("There has been a fatal error during the execution of the Junia game loop:\n%s\n", e);
		}
	}
}

Junia::Engine::Engine()
{
	// init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		// throw error and exit application
		throw "SDL could not be initialized! SDL_Error:\n%s\n", SDL_GetError();
		return;
	}

	this->window = Window();

	// init SDL_image
	int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		throw "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError();
	}

	// temp code
	this->window.create("Junia Window", JM::Vector2<int>(640, 480));
}

Junia::Engine::~Engine()
{
	// destroy window
	this->window.destroy();

	// quit SDL_image
	IMG_Quit();

	// quit SDL
	SDL_Quit();
}

void Junia::Engine::RunGameLoop()
{
	if (this->running) throw "Game Loop already running!";
	this->GameLoop();
}
#include "Window.h"
#include <stdio.h>
#include <string>
#include <iostream>

Junia::Window::Window()
{
	this->window = NULL;
	this->surface = NULL;

	bordered = true;
	resizable = false;

	//temp
	helloWorldTex = Texture();
}

Junia::Window::~Window()
{
	if (window != NULL) this->destroy();
}

Junia::Window::Window(const Junia::Window& w)
{
	this->window = window;
	this->surface = surface;

	this->bordered = w.bordered;
	this->resizable = w.resizable;

	//temp
	helloWorldTex = Texture();
}

Junia::Window& Junia::Window::operator=(const Window& w)
{
	this->window = window;
	this->surface = surface;

	this->bordered = w.bordered;
	this->resizable = w.resizable;

	//temp
	this->helloWorldTex = w.helloWorldTex;

	return *this;
}

void Junia::Window::create(const char* title, Junia::Vector2<int> size)
{
	this->create(title, Junia::Vector2<int>(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), size);
}

void Junia::Window::checkCreated() const
{
	if (window == NULL) {
		throw "Window has to be created first!";
	}
}

void Junia::Window::create(const char* title, Junia::Vector2<int> position, Junia::Vector2<int> size)
{
	if (window != NULL) throw "Window has already been created!";

	// create window
	window = SDL_CreateWindow("GBE Window", position.x, position.y, 100, 100, SDL_WINDOW_SHOWN);
	this->setAsInputSource(true);
	this->setBorder(true);
	this->setGamma(1.0f);
	this->setOpacity(1.0f);
	this->setPosition(position);
	this->setResizable(false);
	this->setSize(size);
	this->setTitle(title);
	this->setWindowed();

	// check for successful window creation
	if (this->window == NULL) {
		// throw error and exit application
		throw (std::string("SDL Window could not be created! SDL_Error: ") + std::string(SDL_GetError()) + std::string("\n"));
		return;
	}

	// get window surface
	this->surface = SDL_GetWindowSurface(this->window);

	// fill the surface with white
	SDL_FillRect(this->surface, NULL, SDL_MapRGB(this->surface->format, 255, 0, 0));

	// update surface
	SDL_UpdateWindowSurface(this->window);

	//temp
	helloWorldTex.LoadTexture("Assets/HelloWorld.png");
	SDL_BlitSurface(helloWorldTex.getSurface(), NULL, this->surface, NULL);
	SDL_UpdateWindowSurface(this->window);
}

void Junia::Window::destroy()
{
	if (window != NULL) SDL_DestroyWindow(this->window);
}

bool Junia::Window::hasBorder() const
{
	this->checkCreated();
	return this->bordered;
}

void Junia::Window::getBordersSize(int* top, int* left, int* bottom, int* right) const
{
	this->checkCreated();
	SDL_GetWindowBordersSize(this->window, top, left, bottom, right);
}

float Junia::Window::getGamma() const
{
	this->checkCreated();
	return SDL_GetWindowBrightness(this->window);
}

int Junia::Window::getDisplayIndex() const
{
	this->checkCreated();
	int di = SDL_GetWindowDisplayIndex(this->window);
	if (di == -1) throw "Error getting the display index! SDL_ERROR:\n%s\n", SDL_GetError();
	return di;
}

void Junia::Window::getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const
{
	this->checkCreated();
	SDL_GetWindowGammaRamp(this->window, red, green, blue);
}

bool Junia::Window::isInputSource() const
{
	this->checkCreated();
	return SDL_GetWindowGrab(this->window);
}

Junia::Vector2<int> Junia::Window::getMaxSize() const
{
	this->checkCreated();
	Junia::Vector2<int> retv;
	SDL_GetWindowMaximumSize(this->window, &retv.x, &retv.y);
	return retv;
}

Junia::Vector2<int> Junia::Window::getMinSize() const
{
	this->checkCreated();
	Junia::Vector2<int> retv;
	SDL_GetWindowMinimumSize(this->window, &retv.x, &retv.y);
	return retv;
}

float Junia::Window::getOpacity() const
{
	this->checkCreated();
	float o;
	if (SDL_GetWindowOpacity(this->window, &o) != 0) {
		throw (std::string("Exception getting window! SDL_ERROR:\n%s\n") + std::string(SDL_GetError()));
	}
	return o;
}

Junia::Vector2<int> Junia::Window::getPosition() const
{
	this->checkCreated();
	Junia::Vector2<int> retv;
	SDL_GetWindowPosition(this->window, &retv.x, &retv.y);
	return retv;
}

bool Junia::Window::isResizable() const
{
	this->checkCreated();
	return this->resizable;
}

Junia::Vector2<int> Junia::Window::getSize() const
{
	this->checkCreated();
	Junia::Vector2<int> retv;
	SDL_GetWindowSize(this->window, &retv.x, &retv.y);
	return retv;
}

const char* Junia::Window::getTitle() const
{
	this->checkCreated();
	return SDL_GetWindowTitle(this->window);
}

void Junia::Window::setBorder(bool bordered)
{
	this->checkCreated();
	SDL_SetWindowBordered(this->window, SDL_bool(bordered));
	this->bordered = bordered;
}

void Junia::Window::setGamma(float gamma)
{
	this->checkCreated();
	SDL_SetWindowBrightness(this->window, gamma);
}

void Junia::Window::setTrueFullscreen()
{
	this->checkCreated();
	SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
}

void Junia::Window::setFakeFullscreen()
{
	this->checkCreated();
	SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Junia::Window::setWindowed()
{
	this->checkCreated();
	SDL_SetWindowFullscreen(this->window, 0);
}

void Junia::Window::setGammaRamp(const Uint16 red[256], const Uint16 green[256], const Uint16 blue[256])
{
	this->checkCreated();
	SDL_SetWindowGammaRamp(this->window, red, blue, green);
}

void Junia::Window::setAsInputSource(const bool use)
{
	this->checkCreated();
	SDL_SetWindowGrab(this->window, SDL_bool(use));
}

//TODO: SDL_SetWindowIcon

void Junia::Window::setMaxSize(const Junia::Vector2<int> size)
{
	this->checkCreated();
	SDL_SetWindowMaximumSize(this->window, size.x, size.y);
}

void Junia::Window::setMinSize(const Junia::Vector2<int> size)
{
	this->checkCreated();
	SDL_SetWindowMinimumSize(this->window, size.x, size.y);
}

void Junia::Window::setOpacity(const float opacity)
{
	this->checkCreated();
	if (opacity < 0.0f || opacity > 1.0f) {
		throw (std::string("Error setting opacity! The opacity has to be between 0.0 and 1.0! It was ") + std::to_string(opacity) + std::string(" instead!"));
	}
	SDL_SetWindowOpacity(this->window, opacity);
}

void Junia::Window::setPosition(const Junia::Vector2<int> position)
{
	this->checkCreated();
	SDL_SetWindowPosition(this->window, position.x, position.y);
}

void Junia::Window::setResizable(const bool resizable)
{
	this->checkCreated();
	SDL_SetWindowResizable(this->window, SDL_bool(resizable));
	this->resizable = resizable;
}

void Junia::Window::setSize(const Junia::Vector2<int> size)
{
	this->checkCreated();
	if (size.x <= 0 || size.y <= 0) {
		throw "Window too small! Window size must be greater than 0 on each axis!";
		return;
	}
	SDL_SetWindowSize(this->window, size.x, size.y);
}

void Junia::Window::setTitle(const char* title)
{
	this->checkCreated();
	SDL_SetWindowTitle(this->window, title);
}
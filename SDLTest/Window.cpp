#include "Window.h"
#include <stdio.h>
#include <string>

Window::Window()
{
	this->window = NULL;
	this->surface = NULL;

	bordered = true;
	resizable = false;
}

Window::~Window()
{
	this->destroy();
}

void Window::create(const char* title, GBM::Vector2i size)
{
	this->create(title, GBM::Vector2i(SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED), size);
}

void Window::create(const char* title, GBM::Vector2i position, GBM::Vector2i size)
{
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
}

void Window::destroy()
{
	SDL_DestroyWindow(this->window);
}

bool Window::hasBorder() const
{
	return this->bordered;
}

void Window::getBordersSize(int* top, int* left, int* bottom, int* right) const
{
	SDL_GetWindowBordersSize(this->window, top, left, bottom, right);
}

float Window::getGamma() const
{
	return SDL_GetWindowBrightness(this->window);
}

int Window::getDisplayIndex() const
{
	int di = SDL_GetWindowDisplayIndex(this->window);
	if (di == -1) throw "Error getting the display index! SDL_ERROR:\n%s\n", SDL_GetError();
	return di;
}

void Window::getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const
{
	SDL_GetWindowGammaRamp(this->window, red, green, blue);
}

bool Window::isInputSource() const
{
	return SDL_GetWindowGrab(this->window);
}

GBM::Vector2i Window::getMaxSize() const
{
	GBM::Vector2i retv;
	SDL_GetWindowMaximumSize(this->window, &retv.x, &retv.y);
	return retv;
}

GBM::Vector2i Window::getMinSize() const
{
	GBM::Vector2i retv;
	SDL_GetWindowMinimumSize(this->window, &retv.x, &retv.y);
	return retv;
}

float Window::getOpacity() const
{
	float o;
	if (SDL_GetWindowOpacity(this->window, &o) != 0) {
		throw (std::string("Exception getting window! SDL_ERROR:\n%s\n") + std::string(SDL_GetError()));
	}
	return o;
}

GBM::Vector2i Window::getPosition() const
{
	GBM::Vector2i retv;
	SDL_GetWindowPosition(this->window, &retv.x, &retv.y);
	return retv;
}

bool Window::isResizable() const
{
	return this->resizable;
}

GBM::Vector2i Window::getSize() const
{
	GBM::Vector2i retv;
	SDL_GetWindowSize(this->window, &retv.x, &retv.y);
	return retv;
}

const char* Window::getTitle() const
{
	return SDL_GetWindowTitle(this->window);
}

void Window::setBorder(bool bordered)
{
	SDL_SetWindowBordered(this->window, SDL_bool(bordered));
	this->bordered = bordered;
}

void Window::setGamma(float gamma)
{
	SDL_SetWindowBrightness(this->window, gamma);
}

void Window::setTrueFullscreen()
{
	SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
}

void Window::setFakeFullscreen()
{
	SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}

void Window::setWindowed()
{
	SDL_SetWindowFullscreen(this->window, 0);
}

void Window::setGammaRamp(const Uint16 red[256], const Uint16 green[256], const Uint16 blue[256])
{
	SDL_SetWindowGammaRamp(this->window, red, blue, green);
	
}

void Window::setAsInputSource(const bool use)
{
	SDL_SetWindowGrab(this->window, SDL_bool(use));
}

//TODO: SDL_SetWindowIcon

void Window::setMaxSize(const GBM::Vector2i size)
{
	SDL_SetWindowMaximumSize(this->window, size.x, size.y);
}

void Window::setMinSize(const GBM::Vector2i size)
{
	SDL_SetWindowMinimumSize(this->window, size.x, size.y);
}

void Window::setOpacity(const float opacity)
{
	if (opacity < 0.0f || opacity > 1.0f) {
		throw (std::string("Error setting opacity! The opacity has to be between 0.0 and 1.0! It was ") + std::to_string(opacity) + std::string(" instead!"));
	}
	SDL_SetWindowOpacity(this->window, opacity);
}

void Window::setPosition(const GBM::Vector2i position)
{
	SDL_SetWindowPosition(this->window, position.x, position.y);
}

void Window::setResizable(const bool resizable)
{
	SDL_SetWindowResizable(this->window, SDL_bool(resizable));
	this->resizable = resizable;
}

void Window::setSize(const GBM::Vector2i size)
{
	if (size.x <= 0 || size.y <= 0) {
		throw "Window too small! Window size must be greater than 0 on each axis!";
		return;
	}
	SDL_SetWindowSize(this->window, size.x, size.y);
}

void Window::setTitle(const char* title)
{
	SDL_SetWindowTitle(this->window, title);
}
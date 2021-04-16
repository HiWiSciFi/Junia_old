#ifndef GB_WINDOW_H_
#define GB_WINDOW_H_

#include "SDL.h"
#include "math\vectors\Vector2i.h"

class Window
{
private:
	//temp
	SDL_Surface* helloWorldSurface;

	SDL_Window* window;
	SDL_Surface* surface;

	bool bordered;
	bool resizable;

	void checkCreated() const;
public:
	// constructor
	Window();
	// destructor
	~Window();

	// copy constructors
	Window(const Window& v);
	Window& operator=(const Window& v);

	// create functions
	void create(const char* title, GBM::Vector2i size);
	void create(const char* title, GBM::Vector2i position, GBM::Vector2i size);

	// destroy window
	void destroy();

	// getter
	bool hasBorder() const;
	void getBordersSize(int* top, int* left, int* bottom, int* right) const;
	float getGamma() const;
	int getDisplayIndex() const;
	void getGammaRamp(Uint16 red[256], Uint16 green[256], Uint16 blue[256]) const;
	bool isInputSource() const;
	GBM::Vector2i getMaxSize() const;
	GBM::Vector2i getMinSize() const;
	float getOpacity() const;
	GBM::Vector2i getPosition() const;
	bool isResizable() const;
	GBM::Vector2i getSize() const;
	const char* getTitle() const;

	// setter
	void setBorder(bool bordered);
	void setGamma(float gamma);
	void setTrueFullscreen();
	void setFakeFullscreen();
	void setWindowed();
	void setGammaRamp(const Uint16 red[256], const Uint16 green[256], const Uint16 blue[256]);
	void setAsInputSource(const bool use);
	//TODO: SDL_SetWindowIcon
	void setMaxSize(const GBM::Vector2i size);
	void setMinSize(const GBM::Vector2i size);
	void setOpacity(const float opacity);
	void setPosition(const GBM::Vector2i position);
	void setResizable(const bool resizable);
	void setSize(const GBM::Vector2i size);
	void setTitle(const char* title);
};

#endif
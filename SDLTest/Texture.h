#ifndef GBA_TEXTURE_H_
#define GBA_TEXTURE_H_

#include "SDL.h"
#include "SDL_image.h"
#include "Math\Vectors\Vector2.h"
#include <string>

class Texture
{
private:
	SDL_Surface* surface;

public:
	// constructors
	Texture();
	Texture(std::string path);

	// destructor
	~Texture();

	// copy constructors
	Texture(const Texture& v);
	Texture& operator=(const Texture& v);

	void LoadTexture(std::string path);
	SDL_Surface* getSurface();
};

#endif
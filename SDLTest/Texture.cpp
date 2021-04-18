#include "Texture.h"
#include <iostream>

Texture::Texture()
{
	surface = NULL;
}

Texture::Texture(std::string path)
{
	surface = NULL;
	LoadTexture(path);
}

Texture::~Texture()
{
	if (surface != NULL) {
		SDL_FreeSurface(surface);
	}
}

Texture::Texture(const Texture& v) {
	this->surface = v.surface;
}

Texture& Texture::operator=(const Texture& v) {
	this->surface = v.surface;
	return *this;
}

void Texture::LoadTexture(std::string path)
{
	SDL_Surface* loadedSurf = IMG_Load(path.c_str());
	if (surface != NULL) {
		SDL_FreeSurface(loadedSurf);
	}
}

SDL_Surface* Texture::getSurface()
{
	return surface;
}

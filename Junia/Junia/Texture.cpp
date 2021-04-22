#include "Texture.h"
#include <iostream>

Junia::Texture::Texture()
{
	surface = NULL;
}

Junia::Texture::Texture(std::string path)
{
	surface = NULL;
	LoadTexture(path);
}

Junia::Texture::~Texture()
{
	if (surface != NULL) {
		SDL_FreeSurface(surface);
	}
}

Junia::Texture::Texture(const Junia::Texture& v) {
	this->surface = v.surface;
}

Junia::Texture& Junia::Texture::operator=(const Junia::Texture& v) {
	this->surface = v.surface;
	return *this;
}

void Junia::Texture::LoadTexture(std::string path)
{
	surface = IMG_Load(path.c_str());
	if (surface == NULL) {
		printf("Error:\n%s\n", IMG_GetError());
	}
}

SDL_Surface* Junia::Texture::getSurface()
{
	return surface;
}

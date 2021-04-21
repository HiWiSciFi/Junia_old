#ifndef JUNIA_TEXTURE_H_
#define JUNIA_TEXTURE_H_

#include "SDL.h"
#include "SDL_image.h"
#include "Math\Vectors\Vector2.h"
#include <string>

namespace Junia {
	class Texture
	{
	private:
		/// @brief the texture surface for the SDL API
		SDL_Surface* surface;

	public:
		/// @brief the default constructor
		Texture();
		/// @brief loads a texture from an image file
		/// @param path the path to the image file to load the texture from
		Texture(std::string path);
		// destructor
		~Texture();

		/// @brief create the texture by copying from another texture
		/// @param v the Texture to copy the attributes from
		Texture(const Texture& v);
		/// @brief set the texture equals to another texture
		/// @param v the texture to copy the attributes from
		/// @return the texture the attributes have been copied to
		Texture& operator=(const Texture& v);

		/// @brief loads an image from a file and sets it as the source for this texture
		/// @param path the path to the image file to load
		void LoadTexture(std::string path);
		/// @brief get the SDL API surface representing the texture
		/// @return the SDL API surface for the texture
		SDL_Surface* getSurface();
	};
}

#endif
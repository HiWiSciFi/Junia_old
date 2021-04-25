#ifndef JUNIA_WINDOW_H_
#define JUNIA_WINDOW_H_

#include "SDL.h"
#include "../JM/vectors/Vector2.h"
#include "Texture.h"

namespace Junia {
	class Window
	{
	private:
		Texture helloWorldTex;

		/// @brief the SDL API window reference
		SDL_Window* window;
		/// @brief the SDL API window surface
		SDL_Surface* surface;

		/// @brief if the window has a border
		bool bordered;
		/// @brief if the window is resizable
		bool resizable;

		/// @brief check if th window has been created
		void checkCreated() const;
	public:
		/// @brief default constructor
		Window();
		// destructor
		~Window();

		/// @brief initialize Window and copy attributes
		/// @param v the window to copy the attributes from
		Window(const Window& v);
		/// @brief set window equals
		/// @param v the window to take the attributes from
		/// @return a reference to a new window created by copying
		Window& operator=(const Window& v);

		/// @brief create the window and show it
		/// @param title the title of the window
		/// @param size the size of the window
		void create(const char* title, JM::Vector2<int> size);
		/// @brief create the window and show it
		/// @param title the title of the window
		/// @param position the position to display the window in
		/// @param size the size of the window
		void create(const char* title, JM::Vector2<int> position, JM::Vector2<int> size);

		/// @brief destroy the window, delete references and call API cleanup
		void destroy();

		/// @brief if the window has a border
		/// @return true, if the window has a border, false otherwise
		bool hasBorder() const;
		/// @brief get the size of the window border
		/// @param top reference to the variable that will hold the top border size
		/// @param left reference to the variable that will hold the left border size
		/// @param bottom reference to the variable that will hold the bottom border size
		/// @param right reference to the variable that will hold the right border size
		void getBordersSize(int* top, int* left, int* bottom, int* right) const;
		/// @brief get the gamma of the window
		/// @return a float value holding the gamma of the window
		float getGamma() const;
		/// @brief get which display the window is being displayed on
		/// @return a int value holding the system index of the display
		int getDisplayIndex() const;
		/// @brief get the gamma ramp of the window
		/// @param red the red curve
		/// @param green the green curve
		/// @param blue the blue curve
		void getGammaRamp(Uint16* red, Uint16* green, Uint16* blue) const;
		/// @brief if the user interaction is restricted to this window
		/// @return true, if the user input is restricted to this window
		bool isGrabbed() const;
		/// @brief get the maximum window size
		/// @return a Vector2 containing the maximum x and y size of the window
		JM::Vector2<int> getMaxSize() const;
		/// @brief get the minimum window size
		/// @return a Vector2 containing the minimum x and y size of the window
		JM::Vector2<int> getMinSize() const;
		/// @brief get the opacity of the window
		/// @return a float holding the windows opacity
		float getOpacity() const;
		/// @brief get the position of the window on the screen
		/// @return a Vector2 containing the position of the window
		JM::Vector2<int> getPosition() const;
		/// @brief if the window is resizable
		/// @return true, if the window is resizable, false otherwise
		bool isResizable() const;
		/// @brief get the size of the window in pixels
		/// @return a Vector2 containing the x and y size of the window
		JM::Vector2<int> getSize() const;
		/// @brief get the title of the window
		/// @return a c string containing the title of the window
		const char* getTitle() const;

		/// @brief set the window border
		/// @param bordered if the border should be shown or not
		void setBorder(bool bordered);
		/// @brief set the window gamma
		/// @param gamma a value between 0.0 and 1.0 to set the window gamma to
		void setGamma(float gamma);
		/// @brief set the window to true fullscreen
		void setTrueFullscreen();
		/// @brief set the window to screen-sized windowed mode
		void setFakeFullscreen();
		/// @brief set the window windowed
		void setWindowed();
		/// @brief set the window gamma ramp
		/// @param red the red curve
		/// @param green the green curve
		/// @param blue the blue curve
		void setGammaRamp(const Uint16 red[256], const Uint16 green[256], const Uint16 blue[256]);
		/// @brief restrict user interaction to this window
		/// @param grab if the user input should be restricted to this window
		void setGrabbed(const bool grab);
		//TODO: SDL_SetWindowIcon
		/// @brief set the maximum size of the window
		/// @param size the x and y size to set the window maximum size to
		void setMaxSize(const JM::Vector2<int> size);
		/// @brief set the minimum size of the window
		/// @param size the x and y size to set the window minimum size to
		void setMinSize(const JM::Vector2<int> size);
		/// @brief set the opacity of the window
		/// @param opacity the opycity between 0.0 and 1.0 to set the window opacity to
		void setOpacity(const float opacity);
		/// @brief set the position of the window
		/// @param position the position to move the window to
		void setPosition(const JM::Vector2<int> position);
		/// @brief set the window resizability
		/// @param resizable if the window is resizable or not
		void setResizable(const bool resizable);
		/// @brief set the size of the window
		/// @param size the size in x and y direction the window should be set to
		void setSize(const JM::Vector2<int> size);
		/// @brief set the title of the window
		/// @param title the c string to set the window title to
		void setTitle(const char* title);
	};
}
#endif
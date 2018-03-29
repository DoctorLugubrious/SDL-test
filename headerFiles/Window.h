#ifndef WIDNOW_DOT_H_
#define WINDOW_DOT_H_

/*
A wrapper class for SDL_Window* so that memory is not leaked
or accessed invalidly
*/

#include <SDL2/SDL.h>
#include <string>

namespace game {

class Window {
public:
	Window();
	Window(const Window& toCopy);
	SDL_Window*& operator*() { return theWindow; };
	~Window();
private:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	SDL_Window* theWindow;
};





}

#endif

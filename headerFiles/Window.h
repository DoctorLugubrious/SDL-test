#ifndef WIDNOW_DOT_H_
#define WINDOW_DOT_H_
#include <string>

#include <SDL2/SDL.h>

namespace game {

/*The Window class is a window to display images on, mainly used to set up the renderer.
 ***Window()
 ***	default constructor
 ***operator*
 ***	for using in calls to SDL functions.
 */


class Window {
public:
	Window();
	Window(const Window& toCopy);
	SDL_Window*& operator*() { return theWindow; };
	~Window();
private:
	SDL_Window* theWindow;
};





}

#endif

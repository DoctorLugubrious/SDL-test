#ifndef WIDNOW_DOT_H_
#define WINDOW_DOT_H_

#include "Window.h"
#include <iostream>
using std::cout;
using std::endl;

namespace game {

//Default constructor that sets up the window to be rendered to
Window::Window(): theWindow(NULL) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else {
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			cout << "Linear texture filtering won't work son." << endl;
		}
		this->theWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED,
		  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(theWindow == NULL) {
			cout << "Window could not be created! SDL_Error: "
				<< SDL_GetError() << endl;
		}
	}
}

//copy constructor
Window::Window(const Window& toCopy): theWindow(NULL) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else {
		this->theWindow = SDL_CreateWindow("Platformer", SDL_WINDOWPOS_UNDEFINED,
		  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(theWindow == NULL) {
			cout << "Window could not be created! SDL_Error: "
				<< SDL_GetError() << endl;
		}
	}
}

//deallocate memory for the window
Window::~Window() {
	if (theWindow != NULL) {
		SDL_DestroyWindow(theWindow);
		theWindow = NULL;
	}
}







}

#endif

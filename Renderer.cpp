#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "Renderer.h"
#include "Exceptions.h"

namespace game {
//init function that sets up the renderer. It is basically so all of my constructors don't use the same
//code. may throw a game::GraphicsException	
void Renderer::init() {
	if (window != NULL) {
		theRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (theRenderer == NULL) {
			std::string error =  "Renderer could not be created: "; 
			error += SDL_GetError();
			throw(GraphicsException(error));
		}
		else {	
			SDL_SetRenderDrawColor (theRenderer, 0xFF, 0xFF, 0xFF, 0x00);
		}
	}
}

//copy constructor
Renderer::Renderer(const Renderer& toCopy): theRenderer(NULL), window(toCopy.window) {
	this->init();
}

//parameterized constructor that takes a reference to an SDL_Window pointer
//and sets up the renderer for that window
Renderer::Renderer(SDL_Window*& initWindow): theRenderer(NULL), window(initWindow) {
	this->init();
}

//Destructor to prevent memory leaks
Renderer::~Renderer() {
	if (theRenderer != NULL) {
		SDL_DestroyRenderer(theRenderer);
		theRenderer = NULL;
	}
}
}


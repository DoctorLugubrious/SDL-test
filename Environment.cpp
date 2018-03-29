//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "Environment.h"
namespace game { 

using std::cout;
using std::endl;

//Environment default constructor
Environment::Environment(): mainWindow(), screenRenderer(*mainWindow)
{

	images.push_back(Texture("gameSprites/neutral.png", *screenRenderer));	
	images.push_back(Texture("gameSprites/up.png", *screenRenderer));	
	images.push_back(Texture("gameSprites/down.png", *screenRenderer));	
	images.push_back(Texture("gameSprites/left.png", *screenRenderer));	
	images.push_back(Texture("gameSprites/right.png", *screenRenderer));	

	images[KEY_DEFAULT].Display();	
}

//runs the game loop
void Environment::gameLoop() {
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.sym) {
					case SDLK_UP: images[KEY_UP].Display();
					break;
					case SDLK_DOWN: images[KEY_DOWN].Display();
					break;
					case SDLK_LEFT: images[KEY_LEFT].Display();
					break;
					case SDLK_RIGHT: images[KEY_RIGHT].Display();
					break;
					default: images[KEY_DEFAULT].Display();
					break;
				}
			}
		}	
	}	
}

//No memory leaks! here's the destructor
Environment::~Environment() {
	SDL_Quit();
}
}

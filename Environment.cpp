//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "Environment.h"
namespace game { 

using std::cout;
using std::endl;

//Environment default constructor
Environment::Environment():
	 player(&images),
	 images() 
{	
}

//runs the game loop
void Environment::gameLoop() {
	bool quit = false;
	SDL_Event event;
	images.Background();
	player.Display();	
	while (!quit) {
		SDL_Delay(1);
		images.Background();
		player.Display();	
		while (SDL_PollEvent(&event) != 0) {	
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYUP) {
				if (
				event.key.keysym.sym == SDLK_LEFT
				|| event.key.keysym.sym == SDLK_RIGHT
				) {
					player.Idle();
				}
			}
			else if (event.type == SDL_KEYDOWN) {
				switch(event.key.keysym.sym) {
					case SDLK_UP:
						player.Jump();
					break;
					case SDLK_LEFT:
						player.MoveLeft();
					break;
					case SDLK_RIGHT:
						player.MoveRight();
					break;
					case SDLK_DOWN:
						player.Duck();
					break;
					default:
						player.Idle();
					break;
				}
			}
		}
		player.UpdatePosition();
	}	
}

//No memory leaks! here's the destructor
Environment::~Environment() {
	SDL_Quit();
}
}

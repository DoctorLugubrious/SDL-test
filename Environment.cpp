//Using SDL and standard IO
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Environment.h"
#include "Exceptions.h"

namespace game { 

using std::cout;
using std::endl;

//Environment default constructor. May throw a GraphicsException object
Environment::Environment():
	player(&images),
	obstacle(&images),
	images() {
	 //Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		std::string error = "SDL_ttf could not initialize! SDL_ttf Error: ";
		error += TTF_GetError();
	    throw(GraphicsException(error));
	}	
}

//runs the game loop
void Environment::gameLoop() {
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		images.Background();
		player.Display();
		obstacle.Display();
		images.Render();	
		SDL_Delay(10);
		while (SDL_PollEvent(&event) != 0) {	
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYUP) {
				if (
				event.key.keysym.sym == SDLK_LEFT
				|| event.key.keysym.sym == SDLK_RIGHT
				|| event.key.keysym.sym == SDLK_DOWN
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
					case SDLK_SPACE:
						player.Attack();
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

//Quits SDL
Environment::~Environment() {
	SDL_Quit();
}
}

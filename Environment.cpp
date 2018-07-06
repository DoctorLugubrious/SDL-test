#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Environment.h"
#include "Exceptions.h"

namespace game { 

using std::cout;
using std::endl;

const int FRAME_RATE = 10;
const int ERROR = -1;

//Environment default constructor. May throw a GraphicsException object
Environment::Environment():
	player(images, enemies),
	obstacle(&images),
	images(),
	enemies(images, player),
	menu (images) {
	 //Initialize SDL_ttf
	if( TTF_Init() == ERROR )
	{
		std::string error = "SDL_ttf could not initialize! SDL_ttf Error: ";
		error += TTF_GetError();
	    	throw(GraphicsException(error));
	}	
}

//runs the game loop
void Environment::gameLoop() {
	bool quit = false;
	bool start = false;
	SDL_Event event;
	while (!quit && !start) {
		SDL_Delay(FRAME_RATE);
		images.Background();
		MenuState state = menu.Render();
		if (state == QUIT) {
			quit = true;
		}
		else if (state == START) {
			start = true;
		}
		images.Render();	
	}
	while (!quit) {
		SDL_Delay(FRAME_RATE);
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
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				obstacle.UpdatePosition(x, y);
			}
		}
		images.Background();
		player.Display();
		enemies.Display(player.GetX(), player.GetY());
		obstacle.Display();
		images.Render();	
	}	
	enemies.Write("high_score.txt");
}

//Quits SDL
Environment::~Environment() {
	SDL_Quit();
}
}

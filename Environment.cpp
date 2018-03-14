//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "Environment.h"
namespace game { 

using std::cout;
using std::endl;

//Environment default constructor
Environment::Environment()
{
	images.push_back(Image("gameSprites/yoSupTest.bmp"));	
	images.push_back(Image("gameSprites/up.bmp"));	
	images.push_back(Image("gameSprites/down.bmp"));	
	images.push_back(Image("gameSprites/left.bmp"));	
	images.push_back(Image("gameSprites/right.bmp"));	

	if(SDL_Init( SDL_INIT_VIDEO) < 0 )
	{
		cout <<"SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}
	else
	{	
		this->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		 SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			cout << "Window could not be created! SDL_Error: " <<
			 SDL_GetError() << endl;
		}
		else
		{
			this->screenSurface = SDL_GetWindowSurface(window);
			images.at(KEY_DEFAULT).DisplayImage(&screenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);
			SDL_UpdateWindowSurface(window); 
	
		}
	}

	
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
					case SDLK_UP:
					images[KEY_UP].DisplayImage(&screenSurface, SCREEN_WIDTH,
						SCREEN_HEIGHT);
					break;
					case SDLK_DOWN:
					images[KEY_DOWN].DisplayImage(&screenSurface, SCREEN_WIDTH,
						SCREEN_HEIGHT);
					break;
					case SDLK_LEFT:
					images[KEY_LEFT].DisplayImage(&screenSurface, SCREEN_WIDTH,
						SCREEN_HEIGHT);
					break;
					case SDLK_RIGHT:
					images[KEY_RIGHT].DisplayImage(&screenSurface, SCREEN_WIDTH,
						SCREEN_HEIGHT);
					break;
					default:
					images[KEY_DEFAULT].DisplayImage(&screenSurface, SCREEN_WIDTH,
						SCREEN_HEIGHT);
					break;
				}
			}
		}
		SDL_UpdateWindowSurface(window);
		
	}	
}

//No memory leaks! here's the destructor
Environment::~Environment() {
	
	SDL_DestroyWindow(window);
	window = NULL;
	SDL_Quit();
}
}

#ifndef HEADER_DOT_H_
#define HEADER_DOT_H_

/*Class Declaration of the Environment class*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Image.h"

namespace game {

enum KeyPressSurfaces {
	KEY_DEFAULT,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
}; 
const int NUM_KEYS = 5;

class Environment {
private:
	static const int SCREEN_WIDTH = 640;
	static const int SCREEN_HEIGHT = 480;
	
	SDL_Surface* currentImage;
	SDL_Surface* screenSurface;
	SDL_Window* window;
	Image images[NUM_KEYS];
public:
	Environment();
	void gameLoop();
	~Environment();
};
}
#endif

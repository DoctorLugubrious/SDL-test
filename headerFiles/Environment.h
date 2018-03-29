#ifndef HEADER_DOT_H_
#define HEADER_DOT_H_

/*Class Declaration of the Environment class, 
which runs the game loop.
*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "Renderer.h"
#include "Window.h"

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
	SDL_Surface* screenSurface;
	Window mainWindow;
	Renderer screenRenderer;
	std::vector<Texture> images;
public:
	Environment();
	//run the game loop
	void gameLoop();
	~Environment();
};
}
#endif

#ifndef ENVIRONMENT_DOT_H_
#define ENVIRONMENT_DOT_H_

/*Class Declaration of the Environment class, 
which runs the game loop.
*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "AnimatedCharacter.h"
#include "ImageLibrary.h"
#include "Platform.h"

namespace game {


class Environment {
private:
	AnimCharacter player;	
	Platform obstacle;
	ImageLibrary images;
public:
	Environment();
	//run the game loop
	void gameLoop();
	~Environment();
};
}
#endif

#ifndef HEADER_DOT_H_
#define HEADER_DOT_H_

/*Class Declaration of the Environment class, 
which runs the game loop.
*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "Character.h"
#include "ImageLibrary.h"

namespace game {


class Environment {
private:
	Character player;
	ImageLibrary images;
public:
	Environment();
	//run the game loop
	void gameLoop();
	~Environment();
};
}
#endif

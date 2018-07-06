#ifndef ENVIRONMENT_DOT_H_
#define ENVIRONMENT_DOT_H_

#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "AnimatedCharacter.h"
#include "ImageLibrary.h"
#include "Platform.h"
#include "EnemyHorde.h"
#include "MainMenu.h"

namespace game {
/*the Environment class runs the game loop. 
 ***Environment()
 ***	Default constructor to set up the images, player, and world
 ***gameLoop()
 ***	Runs the game loop, allowing player input and actions
 ***Destructor
 ***	Closes SDL. The reason no copy constructor or assigment operator is needed
 ***	is that this class does not allocate memory (at least directly) and only needs
 ***	to close SDL
 */

class Environment {
public:
	Environment();
	void gameLoop();
	~Environment();
private:
	AnimCharacter player;	
	Platform obstacle;
	ImageLibrary images;
	EnemyHorde enemies;
	MainMenu menu;
};
}
#endif

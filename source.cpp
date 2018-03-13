/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/
/*Modified by Avery Green for testing purposes 2018*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>
#include "Environment.h"

using std::cout;
using std::endl;
using game::Environment;

int main(int argc, char* argv[]) {
	Environment gameSpace;
	gameSpace.gameLoop();	
	return 0;
}

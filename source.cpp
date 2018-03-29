/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/
/*Modified by Avery Green for testing purposes 2018*/

#include "Environment.h"

using std::cout;
using std::endl;
using game::Environment;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* argv[]) {
	Environment gameSpace;
	gameSpace.gameLoop();	
	return 0;
}

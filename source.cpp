#include "Environment.h"

using game::Environment;

/*
 * Runs the game
 */

int main(int argc, char* argv[]) {
	Environment gameSpace;
	gameSpace.gameLoop();	
	return 0;
}

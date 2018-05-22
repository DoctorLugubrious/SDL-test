#include "Exceptions.h"
#include "Environment.h"
#include <iostream>
using game::Environment;

/*
 * Runs the game
 */

int main(int argc, char* argv[]) {
	Environment gameSpace;
	try {
		gameSpace.gameLoop();
	}	
	catch(game::GraphicsException failState) {
		std::cerr << failState.error << std::endl;
	}
	return 0;
}

#include "Platform.h"
#include "constants.h"
namespace game {

/*Needs an image library pointer to display Images
*/
Platform::Platform(ImageLibrary* init): 
	xPos(WINDOW_WIDTH/2),
	yPos(WINDOW_HEIGHT/2),
	width(280),
	height(240), 		
	sprites(init) {};


/*Displays the platform
*/
void Platform::Display() {
	sprites->Display("PLATFORM"); 
}

/* Returns all 0's if not in, returns the location if in
*/
SDL_Rect Platform::IsIn(int x, int y) {
	return sprites->IsIn("PLATFORM", x, y);
}
}


#include "Platform.h"
#include "constants.h"
namespace game {

/*Needs an image library pointer to display Images
*/
Platform::Platform(ImageLibrary* init): 
	x(WINDOW_WIDTH/2),
	y(WINDOW_HEIGHT/2),
	sprites(init) {};


/*Displays the platform
*/
void Platform::Display() {
	sprites->Display("PLATFORM", x, y); 
}

/* Returns all 0's if not in, returns the location if in
*/
SDL_Rect Platform::IsIn(int x, int y) {
	return sprites->IsIn("PLATFORM", x, y);
}

void Platform::UpdatePosition(int newx, int newy) {
	x = newx;
	y = newy;
}

}


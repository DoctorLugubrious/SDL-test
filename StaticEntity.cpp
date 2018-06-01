#include "StaticEntity.h"

namespace game {

/*
*/
StaticEntity::StaticEntity(int xPos, int yPos, std::string initName, ImageLibrary& library):
	x(xPos),
	y(yPos),
	name(initName),
	images(library) {};

void StaticEntity::Display() {
	images.Display(name, x, y);	
}

SDL_Rect StaticEntity::IsIn(int xPos, int yPos) {
	return images.IsIn(name, xPos, yPos);
}

}

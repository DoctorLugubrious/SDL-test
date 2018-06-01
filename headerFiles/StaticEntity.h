#ifndef STATIC_ENTITY_DOT_H_
#define STATIC_ENTITY_DOT_H_
#include <string>

#include "ImageLibrary.h"

namespace game {
/*The StaticEntity is a base class for things that are not meant to move as well as the character 
 *class, which is meant to move.
 ***StaticEntity(int xPos, int yPos)
 ***	constructs the entity at xPos, yPos
*/

class StaticEntity {
public:
	StaticEntity(int, int, std::string, ImageLibrary&);
	void Display();
	SDL_Rect IsIn(int, int);
private:
	int x;
	int y;

	std::string name;

	ImageLibrary& images;

};

}
#endif

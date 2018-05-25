#ifndef PLATFORM_DOT_H_
#define PLATFORM_DOT_H_

#include <string>

#include "ImageLibrary.h"
namespace game {

/*The platform class is a platform the character can jump on
 ***Platform(ImageLibrary*)
 ***	needs a pointer to an image library to display itself
 ***Display()
 ***	Displays the platform
 ***IsIn(int x, int y)
 **	Returns the area if x,y is in the platform, all 0's otherwise 
 ***UpdatePosition(int x, int y)
 **	changes the location to (x,y) 
 */
class Platform {
public:
	Platform(ImageLibrary*);
	void Display();
	SDL_Rect IsIn(int, int);
	void UpdatePosition(int, int);
private:
	int x;
	int y;
	
	ImageLibrary* sprites;
};
}
#endif

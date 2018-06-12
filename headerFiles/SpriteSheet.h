#ifndef SPRITE_SHEET_DOT_H_
#include <string>
#include <vector>

#include "ImageLibrary.h"
#include "constants.h"

#include <iostream>

namespace game {
/*SpriteSheet is a class for displaying frames of a character 
 *and animating them.
 ***SpriteSheet(ImageLibrary&) 
 ***	The CharacterSpriteSheet needs a refrence to an image library to display
 ***	the sprites it uses
 ***void Display(int x, int y, int frame, CharacterState state);
 ***	Displays the animation. Needs the locations (x and y), the animation frame, and
 ***	the characterState. Returns true if the animation completes.
 */
class SpriteSheet {
public:
	SpriteSheet(ImageLibrary& init): sprites(init) {};
	virtual bool Display(int x, int y, int frame, CharacterState state) = 0;
	virtual ~SpriteSheet() {};
private:
	ImageLibrary& sprites;
};
}


#define SPRITE_SHEET_DOT_H_
#endif


#ifndef ENEMY_SPRITE_SHEET_DOT_H_
#define ENEMY_SPRITE_SHEET_DOT_H_
#include <string>
#include <vector>

#include "ImageLibrary.h"
#include "SpriteSheet.h"

namespace game {
/*CharacterSpriteSheet is a class for displaying frames of the 
 *main character and animating them.
 ***CharacterSpriteSheet(ImageLibrary*) 
 ***	The CharacterSpriteSheet needs a pointer to an image library to display
 ***	the sprites it uses
 ***void Display(int x, int y, int frame, CharacterState state);
 ***	Displays the animation. Needs the locations (x and y), the animation frame, and
 ***	the characterState. Returns true if the animation completes.
 */
class EnemySpriteSheet : public SpriteSheet {
public:
	EnemySpriteSheet(ImageLibrary& init);
	bool Display(int x, int y, int frame, CharacterState state);
private:
	ImageLibrary& sprites;
	std::vector<SDL_Rect> walkFrames;
	std::vector<SDL_Rect> standFrames;
	std::vector<SDL_Rect> attackFrames;	
};
}


#endif


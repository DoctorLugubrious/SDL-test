#ifndef CHARACTER_SPRITE_SHEET_DOT_H_
#define CHARACTER_SPRITE_SHEET_DOT_H_
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
class CharacterSpriteSheet : public SpriteSheet {
public:
	CharacterSpriteSheet(ImageLibrary& init);
	bool Display(int x, int y, int frame, CharacterState state);
private:
	ImageLibrary& sprites;
	std::vector<SDL_Rect> jumpFrames;
	std::vector<SDL_Rect> duckFrames;
	std::vector<SDL_Rect> walkFrames;
	std::vector<SDL_Rect> standFrames;
	std::vector<SDL_Rect> attackFrames;	
	std::vector<SDL_Rect> hurtFrames;	
	std::vector<SDL_Rect> duckAttackFrames;
	std::vector<SDL_Rect> airAttackFrames;
};
}


#endif


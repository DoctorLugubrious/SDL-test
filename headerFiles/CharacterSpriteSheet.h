#ifndef CHARACTER_SPRITE_SHEET_DOT_H_
#define CHARACTER_SPRITE_SHEET_DOT_H_

#include "ImageLibrary.h"
#include "constants.h"
#include <string>
#include <vector>

namespace game {

	class CharacterSpriteSheet {
		public:
			CharacterSpriteSheet(ImageLibrary* init);
			void Display(int x, int y, int frame, CharacterState state);
		private:
			ImageLibrary* sprites;
			std::vector<SDL_Rect> jumpFrames;
			std::vector<SDL_Rect> duckFrames;
			std::vector<SDL_Rect> walkFrames;
			std::vector<SDL_Rect> standFrames;	
	};

}


#endif


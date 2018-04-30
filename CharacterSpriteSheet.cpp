#include "CharacterSpriteSheet.h"
namespace game {


	CharacterSpriteSheet::CharacterSpriteSheet(ImageLibrary* init):
		sprites(init),
		jumpFrames(1),
		duckFrames(1),
		walkFrames(8),
		standFrames(8) {
		SDL_Rect test = {0, 0, 0, SPRITE_HEIGHT};

		//Set clips for standing animation		
		test.w = STAND_SPRITE_WIDTH;
		for(size_t i = 0; i < standFrames.size(); ++i) {
			test.x = STAND_SPRITE_WIDTH * i;
			standFrames.at(i) = test;
		}	
		////////////////////////////////
		//Set clips for standing animation
		test.y = SPRITE_HEIGHT;		
		test.w = WALK_SPRITE_WIDTH;
		for(size_t i = 0; i < standFrames.size(); ++i) {
			test.x = WALK_SPRITE_WIDTH * i;
			walkFrames.at(i) = test;
		}	
		////////////////////////////////
		//Set clips for ducking animation;
		test.y += SPRITE_HEIGHT;
		test.w = STAND_SPRITE_WIDTH;
		test.x = 0;
		duckFrames.at(0) = test;
		//////////////////////////////
	}
	
	void CharacterSpriteSheet::Display(int x, int y, int frame, CharacterState state) {
		const int FRAME_RATE = 5;
		int sprite = (frame / FRAME_RATE) % standFrames.size();
		switch(state) {
			case WALK_LEFT:
				sprites->Display("LUCARIO", x, y, walkFrames.at(sprite));
			break;
			case WALK_RIGHT:
				sprites->DisplayFlipped("LUCARIO", x, y, walkFrames.at(sprite));
			break;
			case DUCK_LEFT:
				sprites->Display("LUCARIO", x, y, duckFrames.at(0));
			break;
			case DUCK_RIGHT:
				sprites->DisplayFlipped("LUCARIO", x, y, duckFrames.at(0));
			break;
			case STAND_LEFT:
				sprites->Display("LUCARIO", x, y, standFrames.at(sprite));
			break;
			case STAND_RIGHT:
				sprites->DisplayFlipped("LUCARIO", x, y, standFrames.at(sprite));
			break;
			default:
				sprites->Display("LUCARIO", x, y, standFrames.at(sprite));
		}
	}

}




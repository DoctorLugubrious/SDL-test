#include "CharacterSpriteSheet.h"
namespace game {

/* Sets up the character sprite sheet as long as the ImageLibrary* is valid.
 */
CharacterSpriteSheet::CharacterSpriteSheet(ImageLibrary* init):
	sprites(init),
	jumpFrames(4),
	duckFrames(1),
	walkFrames(8),
	standFrames(8),
	attackFrames(16) {

	SDL_Rect test = {0, 0, 0, SPRITE_HEIGHT};

	//Set clips for standing animation		
	test.w = STAND_SPRITE_WIDTH;
	for(size_t i = 0; i < standFrames.size(); ++i) {
		test.x = STAND_SPRITE_WIDTH * i;
		standFrames.at(i) = test;
	}	
	////////////////////////////////
	//Set clips for walking animation
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
	//Set clips for jumping animation
	test.y += SPRITE_HEIGHT;		
	for(size_t i = 0; i < jumpFrames.size(); ++i) {
		test.x = STAND_SPRITE_WIDTH * i;
		jumpFrames.at(i) = test;
	}	
	///////////////////////////////////
	//Set clips for attacking animation
	test.y += SPRITE_HEIGHT;		
	test.w = WALK_SPRITE_WIDTH;
	for(size_t i = 0; i < attackFrames.size(); ++i) {
		test.x = WALK_SPRITE_WIDTH * i;
		attackFrames.at(i) = test;
	}	
	////////////////////////////////
}


/* Displays the sprite for the current frame at the current position
*/
//CHANGE TO bool LATER	
CharacterState CharacterSpriteSheet::Display(int x, int y, int frame, CharacterState state) {
	const int FRAME_RATE = 5;
	size_t sprite = (frame / FRAME_RATE) % standFrames.size();
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
		case JUMP_LEFT:
			if (sprite >= jumpFrames.size()) {
				sprites->Display("LUCARIO", x, y, jumpFrames.at(3));
			}
			else {
				sprites->Display("LUCARIO", x, y, jumpFrames.at(sprite));
			}
			break;
		case JUMP_RIGHT:
			if (sprite >= jumpFrames.size()) {
				sprites->DisplayFlipped("LUCARIO", x, y, jumpFrames.at(3));
			}
			else {
				sprites->DisplayFlipped("LUCARIO", x, y, jumpFrames.at(sprite));
			}
			break;
		case ATTACK_LEFT:
			sprite = (frame / 2);
			if (sprite > 11) {
				this->Display(x, y, frame, STAND_LEFT);
				return STAND_LEFT;
			}
			sprite %= 12;
			sprites->Display("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case ATTACK_RIGHT:
			sprite = (frame / 2);
			if (sprite > 11) {
				this->Display(x, y, frame, STAND_RIGHT);
				return STAND_RIGHT;
			}
			sprite %= 12;
			sprites->DisplayFlipped("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case AURA_SPHERE_LEFT:
			sprite = 12 + (frame % 4);
			sprites->Display("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case AURA_SPHERE_RIGHT:
			sprite = 12 + (frame % 4);
			sprites->DisplayFlipped("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		default:
			sprites->Display("LUCARIO", x, y, standFrames.at(sprite));
	}
	return state;
}

}




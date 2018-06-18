#include "EnemySpriteSheet.h"
#include <iostream>
namespace game {

/* Sets up the character sprite sheet as long as the ImageLibrary* is valid.
 */


const int WALK_FRAMES = 4;
const int STAND_FRAMES = 1;
const int ATTACK_FRAMES = 5;

const int SPRITE_HEIGHT = 38;
const int SPRITE_WIDTH = 46;

EnemySpriteSheet::EnemySpriteSheet(ImageLibrary& init):
	SpriteSheet(init),
	sprites(init),
	walkFrames(WALK_FRAMES),
	standFrames(STAND_FRAMES),
	attackFrames(ATTACK_FRAMES) {
	SDL_Rect test = {0, 0, 0, SPRITE_HEIGHT};

	//Set clips for standing animation		
	test.w = SPRITE_WIDTH;
	for(size_t i = 0; i < standFrames.size(); ++i) {
		test.x = SPRITE_WIDTH * i;
		standFrames.at(i) = test;
	}	
	////////////////////////////////
	//Set clips for walking animation
	test.y = SPRITE_HEIGHT;		
	test.w = SPRITE_WIDTH;
	for(size_t i = 0; i < walkFrames.size(); ++i) {
		test.x = SPRITE_WIDTH * i;
		walkFrames.at(i) = test;
	}	
	////////////////////////////////
	//Set clips for attacking animation
	test.y += SPRITE_HEIGHT;		
	test.w = SPRITE_WIDTH;
	for(size_t i = 0; i < attackFrames.size(); ++i) {
		test.x = SPRITE_WIDTH * i;
		attackFrames.at(i) = test;
	}	
	////////////////////////////////
}


/* Displays the sprite for the current frame at the current position
*/
bool EnemySpriteSheet::Display(int x, int y, int frame, CharacterState state) {
	const int FRAME_RATE = 5;
	const int ATTACK_FRAME_RATE = 2;
	size_t sprite = (frame / FRAME_RATE);
	switch(state) {
		case WALK_LEFT:
			sprite %= WALK_FRAMES;
			sprites.Display("BIDOOF", x, y, walkFrames.at(sprite));
			break;
		case WALK_RIGHT:
			sprite %= WALK_FRAMES;
			sprites.DisplayFlipped("BIDOOF", x, y, walkFrames.at(sprite));
			break;
		case STAND_LEFT:
			sprites.Display("BIDOOF", x, y, standFrames.back());
			break;
		case STAND_RIGHT:
			sprites.DisplayFlipped("BIDOOF", x, y, standFrames.back());
			break;
		case ATTACK_LEFT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, STAND_LEFT);
				return true;
			}
			sprite %= ATTACK_FRAMES;
			sprites.Display("BIDOOF", x, y, attackFrames.at(sprite));
			break;
		case ATTACK_RIGHT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, STAND_RIGHT);
				return true;
			}
			sprite %= ATTACK_FRAMES;
			sprites.DisplayFlipped("BIDOOF", x, y, attackFrames.at(sprite));
			break;
		case HURT_RIGHT:
			return true;
		case HURT_LEFT:
			return true;
		default:
			sprite %= STAND_FRAMES;
			sprites.Display("BIDOOF", x, y, standFrames.at(sprite));
	}
	return false;
}

}




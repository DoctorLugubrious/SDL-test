#include "CharacterSpriteSheet.h"
namespace game {

/* Sets up the character sprite sheet as long as the ImageLibrary* is valid.
 */

const int JUMP_FRAMES = 4;
const int DUCK_FRAMES = 1;
const int WALK_FRAMES = 8;
const int STAND_FRAMES = 8;
const int ATTACK_FRAMES = 16;
const int HURT_FRAMES = 7;
const int DUCK_ATTACK_FRAMES = 5;
const int AIR_ATTACK_FRAMES = 8;

const int ATTACK_SPRITES = 12;
const int AURA_FRAMES = 4;

CharacterSpriteSheet::CharacterSpriteSheet(ImageLibrary& init):
	SpriteSheet(init),
	sprites(init),
	jumpFrames(JUMP_FRAMES),
	duckFrames(DUCK_FRAMES),
	walkFrames(WALK_FRAMES),
	standFrames(STAND_FRAMES),
	attackFrames(ATTACK_FRAMES),
	hurtFrames(HURT_FRAMES),
	duckAttackFrames(DUCK_ATTACK_FRAMES),
	airAttackFrames(AIR_ATTACK_FRAMES) {

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
	//Set clips for hurt animation
	test.y += SPRITE_HEIGHT;		
	for(size_t i = 0; i < hurtFrames.size(); ++i) {
		test.x = WALK_SPRITE_WIDTH * i;
		hurtFrames.at(i) = test;
	}	
	////////////////////////////////
	//Set clips for attack animation
	test.y += SPRITE_HEIGHT;		
	for(size_t i = 0; i < duckAttackFrames.size(); ++i) {
		test.x = WALK_SPRITE_WIDTH * i;
		duckAttackFrames.at(i) = test;
	}	
	////////////////////////////////
	//Set clips for attack animation
	test.y += SPRITE_HEIGHT;		
	for(size_t i = 0; i < airAttackFrames.size(); ++i) {
		test.x = WALK_SPRITE_WIDTH * i;
		airAttackFrames.at(i) = test;
	}	
	////////////////////////////////
}


/* Displays the sprite for the current frame at the current position
*/
bool CharacterSpriteSheet::Display(int x, int y, int frame, CharacterState state) {
	const int FRAME_RATE = 5;
	const int ATTACK_FRAME_RATE = 2;
	size_t sprite = (frame / FRAME_RATE) % standFrames.size();
	switch(state) {
		case WALK_LEFT:
			sprites.DisplayFlipped("LUCARIO", x, y, walkFrames.at(sprite));
			break;
		case WALK_RIGHT:
			sprites.Display("LUCARIO", x, y, walkFrames.at(sprite));
			break;
		case DUCK_LEFT:
			sprites.DisplayFlipped("LUCARIO", x, y, duckFrames.at(0));
			break;
		case DUCK_RIGHT:
			sprites.Display("LUCARIO", x, y, duckFrames.at(0));
			break;
		case STAND_LEFT:
		sprites.DisplayFlipped("LUCARIO", x, y, standFrames.at(sprite));
			break;
		case STAND_RIGHT:
			sprites.Display("LUCARIO", x, y, standFrames.at(sprite));
			break;
		case JUMP_LEFT:
			if (sprite >= jumpFrames.size()) {
				sprites.DisplayFlipped("LUCARIO", x, y, jumpFrames.at(JUMP_FRAMES - 1));
			}
			else {
				sprites.DisplayFlipped("LUCARIO", x, y, jumpFrames.at(sprite));
			}
			break;
		case JUMP_RIGHT:
			if (sprite >= jumpFrames.size()) {
				sprites.Display("LUCARIO", x, y, jumpFrames.at(JUMP_FRAMES - 1));
			}
			else {
				sprites.Display("LUCARIO", x, y, jumpFrames.at(sprite));
			}
			break;
		case RANGED_ATTACK_LEFT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > ATTACK_SPRITES - 1) {
				this->Display(x, y, frame, STAND_LEFT);
				return true;
			}
			sprite %= ATTACK_SPRITES;
			sprites.DisplayFlipped("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case RANGED_ATTACK_RIGHT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > ATTACK_SPRITES - 1) {
				this->Display(x, y, frame, STAND_RIGHT);
				return true;
			}
			sprite %= ATTACK_SPRITES;
			sprites.Display("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case AURA_SPHERE_LEFT:
			sprite = ATTACK_SPRITES + (frame / FRAME_RATE % AURA_FRAMES);
			sprites.DisplayFlipped("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case AURA_SPHERE_RIGHT:
			sprite = ATTACK_SPRITES + (frame / FRAME_RATE % AURA_FRAMES);
			sprites.Display("LUCARIO", x, y, attackFrames.at(sprite));
			break;
		case HURT_LEFT:
			if (sprite >= hurtFrames.size()) {
				sprites.DisplayFlipped("LUCARIO", x, y, hurtFrames.at(HURT_FRAMES - 1));
				return true;
			}
			else {
				sprites.DisplayFlipped("LUCARIO", x, y, hurtFrames.at(sprite));
			}
			break;
		case HURT_RIGHT:
			if (sprite >= hurtFrames.size()) {
				sprites.Display("LUCARIO", x, y, hurtFrames.at(HURT_FRAMES - 1));
				return true;
			}
			else {
				sprites.Display("LUCARIO", x, y, hurtFrames.at(sprite));
			}
			break;
		case DUCK_ATTACK_LEFT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > DUCK_ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, STAND_LEFT);
				return true;
			}
			sprite %= DUCK_ATTACK_FRAMES;
			sprites.DisplayFlipped("LUCARIO", x, y, duckAttackFrames.at(sprite));
			break;
		case DUCK_ATTACK_RIGHT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > DUCK_ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, STAND_RIGHT);
				return true;
			}
			sprite %= DUCK_ATTACK_FRAMES;
			sprites.Display("LUCARIO", x, y, duckAttackFrames.at(sprite));
			break;
		case AIR_ATTACK_LEFT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > AIR_ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, JUMP_LEFT);
				return true;
			}
			sprite %= AIR_ATTACK_FRAMES;
			sprites.DisplayFlipped("LUCARIO", x, y, airAttackFrames.at(sprite));
			break;
		case AIR_ATTACK_RIGHT:
			sprite = (frame / ATTACK_FRAME_RATE);
			if (sprite > DUCK_ATTACK_FRAMES - 1) {
				this->Display(x, y, frame, JUMP_RIGHT);
				return true;
			}
			sprite %= AIR_ATTACK_FRAMES;
			sprites.Display("LUCARIO", x, y, airAttackFrames.at(sprite));
			break;
		default:
			sprites.Display("LUCARIO", x, y, standFrames.at(sprite));
	}
	return false;
}

}




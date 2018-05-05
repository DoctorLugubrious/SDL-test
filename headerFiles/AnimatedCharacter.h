#ifndef ANIM_CHARACTER_DOT_H_
#define ANIM_CHARACTER_DOT_H_

#include "ImageLibrary.h"
#include "CharacterSpriteSheet.h"
#include <string>
namespace game {

	/*
	 * The animated character class is the playable character for the game
	 */

	class AnimCharacter {
	public:
		AnimCharacter(ImageLibrary* init);
		void MoveRight();
		void MoveLeft();
		void Jump();
		void Idle();
		void Duck();
		void UpdatePosition();
		void Display();
	private:
		bool Collide();
		int xPos;
		int yPos;
		int xVelocity;
		int yVelocity;
		size_t width;
		size_t height;
		ImageLibrary* sprites;
		CharacterState currentSprite;
		bool jump;
		CharacterSpriteSheet spriteSheet;
		size_t frame;
	};
}
#endif

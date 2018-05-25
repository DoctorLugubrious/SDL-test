#ifndef ANIM_CHARACTER_DOT_H_
#define ANIM_CHARACTER_DOT_H_

#include <string>

#include "ImageLibrary.h"
#include "CharacterSpriteSheet.h"
#include "AuraSphere.h"

namespace game {

/*
 * The animated character class is the playable character for the game.
 **********************************************************************
 ***AnimCharacter(ImageLibrary*)
 ***	Initializes the data. Requires a game::ImageLibrary pointer to display images.
 ***MoveRight()
 ***	Called whenever the player is moving right. Accelerates the player each time
 ***	it is called until its momentum is stopped. Displays the running animation
 ***MoveLeft()
 ***	same as above, but moves left
 ***Jump()
 ***	to be called while the player is jumping. Increases their upward velocity.
 ***	Displays the running animation
 ***Idle()
 ***	Stops movement and displays the idle animation.
 ***Duck()
 ***	Stops movement, increases gravity, and displays the duck sprite
 ***UpdatePosition()
 ***	To be called immediately before Display, updates the player's position
 ***Display()
 ***	Writes the sprite of the current animation at the current location to the renderer.
 ***Attack()
 ***	The player shoots a projectile and plays an attacking animation
 */

class AnimCharacter {
public:
	AnimCharacter(ImageLibrary*);
	void MoveRight();
	void MoveLeft();
	void Jump();
	void Idle();
	void Duck();
	void UpdatePosition();
	void Display();
	void Attack();
private:
	bool Collide();
	void Floor(int height);
	void FinishAnimation();

	bool jump;

	int xPos;
	int yPos;
	int xVelocity;
	int yVelocity;
	size_t frame;
	CharacterState currentSprite;
	CharacterState previousSprite;

	ImageLibrary* sprites;
	
	AuraSphere projectile;

	CharacterSpriteSheet spriteSheet;

};
}
#endif

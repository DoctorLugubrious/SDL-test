#ifndef ANIM_CHARACTER_DOT_H_
#define ANIM_CHARACTER_DOT_H_

#include <string>
#include <list>

#include "ImageLibrary.h"
#include "CharacterSpriteSheet.h"
#include "AuraSphere.h"
#include "Character.h"
#include "EnemyHorde.h"

namespace game {

/*
 * The animated character class is the playable character for the game.
 **********************************************************************
 ***AnimCharacter(ImageLibrary&, EnemyHorde&)
 ***	Initializes the data. Requires a game::ImageLibrary reference to display images.
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

class AnimCharacter: public Character {
public:
	AnimCharacter(ImageLibrary&, EnemyHorde&);
	void Jump();
	void Duck();
	void Display();
	void Attack();
private:
	int GetXSpeed() { return X_VELOCITY_MAX; };
	int GetXAcceleration() {return X_ACCELERATION;};	
	int GetYAcceleration() {return Y_ACCELERATION;};	
	int GetGravity() {return GRAVITY;};	
	int GetHeight() {return SPRITE_HEIGHT;};
	int GetWidth() {return STAND_SPRITE_WIDTH;};
	
	ImageLibrary& sprites;
	EnemyHorde& enemies;
	
	std::list<AuraSphere> projectiles;

	CharacterSpriteSheet spriteSheet;

};
}
#endif

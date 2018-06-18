#ifndef ENEMY_DOT_H_
#define ENEMY_DOT_H_

#include <string>

#include "ImageLibrary.h"
#include "EnemySpriteSheet.h"
#include "Character.h"


namespace game {

class AnimCharacter;
/*
 * The enemy class is the enemies for the game.
 **********************************************************************
 ***Enemy(ImageLibrary*)
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
 ***	Jumps, dealing damage
 */

class Enemy: public Character {
public:
	Enemy(ImageLibrary&);
	Enemy(const Enemy& toCopy):	
		Character(toCopy.sprites, spriteSheet),
		sprites(toCopy.sprites),
		spriteSheet(sprites) {};
	void Attack();
	void Attack(AnimCharacter& player);
private:
	int GetXSpeed() { return 5; };
	int GetXAcceleration() {return 1;};	
	int GetYAcceleration() {return Y_ACCELERATION;};	
	int GetGravity() {return GRAVITY;};	
	int GetHeight() {return 38;}
	int GetWidth() {return 46;}
	ImageLibrary& sprites;
	
	EnemySpriteSheet spriteSheet;

};
}
#endif

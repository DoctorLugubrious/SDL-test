#ifndef CHARACTER_DOT_H_
#define CHARACTER_DOT_H_

#include <string>
#include "constants.h"
#include "SpriteSheet.h"
#include "StaticEntity.h"

namespace game {

/*
 * The character class is the abstract base class for anything that's a character.
 **********************************************************************
 ***Character(ImageLibrary*)
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

class Character {
public:
	Character();
	void MoveRight();
	void MoveLeft();
	void Attack();
	void Idle();
	virtual void Display();
	virtual ~Character() {};
	virtual int GetYAcceleration() = 0;
	virtual int GetXAcceleration() = 0;
	virtual int GetGravity() = 0;
private:
	bool Collide();
	void Floor(int height);
	void Wall(int position);
	void Ceiling(int height);
	void UpdatePosition();

	int xPos;
	int yPos;
	int xVelocity;
	int yVelocity;
	size_t frame;

	CharacterState currentSprite;
	CharacterState previousSprite;

	SpriteSheet* sprites;

};
}
#endif

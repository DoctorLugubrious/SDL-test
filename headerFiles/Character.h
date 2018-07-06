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
 ***IsIn(int, int)
 ***	returns true if the given coordinate is in the character 
 ***SetPos(int, int)
 ***	sets the initial position
 ***PROTECTED
 */

class Character {
public:
	Character(ImageLibrary&, SpriteSheet&);
	Character(const Character& toCopy);
	virtual void MoveRight();
	virtual void MoveLeft();
	virtual void Attack() = 0;
	virtual void Idle();
	virtual void Display();
	virtual ~Character() {};
	int GetX() {return xPos;};
	int GetY() {return yPos;};
	void Die();
	bool Dead() { return reallyDead; };
	bool IsIn(int, int);
	void SetPos(int, int);
protected:
	virtual int GetXSpeed() = 0;
	virtual int GetYAcceleration() = 0;
	virtual int GetXAcceleration() = 0;
	virtual int GetGravity() = 0;
	virtual int GetHeight() = 0;
	virtual int GetWidth() = 0;
	void SetState(CharacterState current, CharacterState previous);
	void SetState(CharacterState current);
	CharacterState GetState() {return currentSprite;};
	CharacterState pGetState() {return previousSprite;};
	void SetJump(bool newJump);
	bool GetJump() {return jump;};
	void SetXVelocity(int xVelocity);	
	void SetYVelocity(int yVelocity);
	int GetXVelocity() {return xVelocity;};	
	int GetYVelocity() {return yVelocity;};
	size_t GetFrame() {return frame;};
	void ResetFrame();
	void SetDead(bool state);	
	void SetReallyDead(bool state);	
private:
	bool Collide();
	void Floor(int height);
	void Wall(int position);
	void Ceiling(int height);
	void UpdatePosition();
	void FinishAnimation();
	bool jump;
	bool dead;
	bool reallyDead;
	size_t frame;
	int xPos;
	int yPos;
	int xVelocity;
	int yVelocity;
	CharacterState currentSprite;
	CharacterState previousSprite;


	SpriteSheet& sprites;
	ImageLibrary& library;

};
}
#endif

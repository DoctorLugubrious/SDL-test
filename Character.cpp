#include "Character.h"
#include "constants.h"
#include <iostream>
using std::cout;
using std::endl;

namespace game {

	/*
	 *The Character class needs an ImageLibrary pointer to
	 *display images, but other than that, takes care of itself.
	 */ 	
	Character::Character(ImageLibrary* init) :
		xPos (0),
		yPos (0),
		xVelocity(0),
		yVelocity(0),
		width (60),
		height (48),
		sprites(init),
		currentSprite("NEUTRAL"),
		jump(false)
		 {};

	//moves the character right
	void Character::MoveRight() {
		if (xVelocity < 0) {
			xVelocity = 0;
		}
		if (xVelocity > X_VELOCITY_MAX) {
			xVelocity = X_VELOCITY_MAX;
		}
		xVelocity += X_ACCELERATION;
		currentSprite = "RIGHT";
	}

	//moves the character left
	void Character::MoveLeft() {
		if (xVelocity > 0) {
			xVelocity = 0;
		}
		if (xVelocity < -X_VELOCITY_MAX) {
			xVelocity = -X_VELOCITY_MAX;
		}
		xVelocity -= X_ACCELERATION;
		currentSprite = "LEFT";
	}

	//lets the character jump
	void Character::Jump() {
		if (!jump) {
			yVelocity += Y_ACCELERATION;
			jump = true;
		}

		currentSprite = "UP";
	}
	
	//ducks the character, which makes them fall faster
	void Character::Duck() {
		xVelocity = 0;
		yVelocity -= GRAVITY;
		currentSprite = "DOWN";
	}
	
	//Call this when you stop moving left or right
	void Character::Idle() {	
		xVelocity = 0;
		yVelocity = 0;
		currentSprite = "NEUTRAL";
	}
	
	//updates the positions and velocities of the character for one frame
	void Character::UpdatePosition() {
		yVelocity -= GRAVITY;
		xPos += xVelocity;
		yPos -= yVelocity;
		if (xPos > X_LIMIT) { xPos = X_MIN; }
		if (xPos < X_MIN) { xPos = X_LIMIT; }
		if (yPos > 0) {
			yPos = 0;
			yVelocity = 0;
			jump = false;
		 }
	}

	//Displays the current sprite
	void Character::Display() {
		sprites->Display(currentSprite.c_str(), xPos, yPos);
	}
}

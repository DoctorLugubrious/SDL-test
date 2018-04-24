#include "Character.h"

#include <iostream>
using std::cout;
using std::endl;

namespace game {
	const int X_LIMIT = 620;
	const int Y_LIMIT = 480;
	const int X_MIN = -50;
	const int X_ACCELERATION = 1;
	const int Y_ACCELERATION = 20;

	const int X_VELOCITY_MAX = 5;
	const int Y_VELOCITY_MAX = 5;
	
	const int GRAVITY = 1;
	
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

	void Character::Jump() {
		if (!jump) {
			yVelocity += Y_ACCELERATION;
			jump = true;
		}

		currentSprite = "UP";
	}
	
	void Character::Duck() {
		xVelocity = 0;
		yVelocity -= GRAVITY;
		currentSprite = "DOWN";
	}
	
	void Character::Idle() {	
		xVelocity = 0;
		yVelocity = 0;
		currentSprite = "NEUTRAL";
	}
	
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

	void Character::Display() {
		sprites->Display(currentSprite.c_str(), xPos, yPos);
	}
}

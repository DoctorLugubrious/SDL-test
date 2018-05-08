#include "AnimatedCharacter.h"
#include "constants.h"
#include <iostream>
using std::cout;
using std::endl;

namespace game {

	/*
	 *The AnimCharacter class needs an ImageLibrary pointer to
	 *display images, but other than that, takes care of itself.
	 */ 	
	AnimCharacter::AnimCharacter(ImageLibrary* init) :
		xPos (0),
		yPos (0),
		xVelocity(0),
		yVelocity(0),
		width (60),
		height (48),
		sprites(init),
		currentSprite(STAND_RIGHT),
		jump(false),
		spriteSheet(init),	
		frame(0)
		 {};

	//moves the character right
	void AnimCharacter::MoveRight() {
		if (xVelocity < 0) {
			xVelocity = 0;
		}
		if (xVelocity > X_VELOCITY_MAX) {
			xVelocity = X_VELOCITY_MAX;
		}
		xVelocity += X_ACCELERATION;
		currentSprite = WALK_LEFT;
	}

	//moves the character left
	void AnimCharacter::MoveLeft() {
		if (xVelocity > 0) {
			xVelocity = 0;
		}
		if (xVelocity < -X_VELOCITY_MAX) {
			xVelocity = -X_VELOCITY_MAX;
		}
		xVelocity -= X_ACCELERATION;
		currentSprite = WALK_RIGHT;
	}

	//lets the character jump
	void AnimCharacter::Jump() {
		if (!jump) {
			yVelocity += Y_ACCELERATION;
			jump = true;
			if (xVelocity > 0) {
				currentSprite = JUMP_LEFT;
			}
			else {
				currentSprite = JUMP_RIGHT;
			}
			frame = 0;
		}
	}
	
	//ducks the character, which makes them fall faster
	void AnimCharacter::Duck() {
		if (currentSprite == WALK_RIGHT 
			||currentSprite == STAND_RIGHT
			||currentSprite == DUCK_RIGHT
			||currentSprite == JUMP_RIGHT
		) {
			currentSprite = DUCK_RIGHT;
		}
		else {
			currentSprite = DUCK_LEFT;
		}
		xVelocity = 0;
		yVelocity -= GRAVITY;
	}
	
	//Call this when you stop moving left or right
	void AnimCharacter::Idle() {	
		xVelocity = 0;
		yVelocity = 0;
		if (currentSprite == WALK_RIGHT 
			||currentSprite == STAND_RIGHT
			||currentSprite == DUCK_RIGHT
			||currentSprite == JUMP_RIGHT
		) {
			currentSprite = STAND_RIGHT;
		}
		else {
			currentSprite = STAND_LEFT;
		}
	}
	
	//updates the positions and velocities of the character for one frame
	void AnimCharacter::UpdatePosition() {
		xPos += xVelocity;
		yPos -= yVelocity;
		if (!Collide()) {
			yVelocity -= GRAVITY;
		}
		++frame;
	}

	//Displays the current sprite
	void AnimCharacter::Display() {
		spriteSheet.Display(xPos, yPos, frame, currentSprite);
	}

	bool AnimCharacter::Collide() {
		if (xPos > X_LIMIT) { xPos = X_MIN; }
		if (xPos < X_MIN) { xPos = X_LIMIT; }
		if (yPos > WINDOW_HEIGHT - SPRITE_HEIGHT || sprites->IsIn("PLATFORM", xPos, yPos)) {
			jump = false;
			yVelocity = 0;
			if (currentSprite == JUMP_RIGHT) {
				if (xVelocity != 0) {
						currentSprite = WALK_RIGHT;
				}
				else {
					currentSprite = STAND_RIGHT;
				}
			}
			else if (currentSprite == JUMP_LEFT) {
				if (xVelocity != 0) {
						currentSprite = WALK_LEFT;
				}
				else {
					currentSprite = STAND_LEFT;
				}
			}
			return true;
		}
		return false;

	}
}

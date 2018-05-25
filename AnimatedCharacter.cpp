#include <iostream>
#include <algorithm>

#include "constants.h"
#include "AnimatedCharacter.h"
using std::cout;
using std::endl;

namespace game {

/*
 *The AnimCharacter class needs an ImageLibrary pointer to
 *display images, but other than that, takes care of itself.
 */ 	
AnimCharacter::AnimCharacter(ImageLibrary* init) :
	jump(false),
	xPos (0),
	yPos (0),
	xVelocity(0),
	yVelocity(0),
	frame(0),
	currentSprite(STAND_RIGHT),
	previousSprite(STAND_RIGHT),
	sprites(init),
	projectile(&spriteSheet),
	spriteSheet(init) {};

//moves the character left
void AnimCharacter::MoveLeft() {
	if (xVelocity > 0) {
		xVelocity = 0;
	}
	currentSprite = WALK_LEFT;
}

//moves the character right
void AnimCharacter::MoveRight() {
	if (xVelocity < 0) {
		xVelocity = 0;
	}
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
	if (currentSprite == WALK_LEFT) {
		xVelocity -= X_ACCELERATION;
	}
	else if (currentSprite == WALK_RIGHT) {
		xVelocity += X_ACCELERATION;
	}
	if (xVelocity > X_VELOCITY_MAX) {
		xVelocity = X_VELOCITY_MAX;
	}
	if (xVelocity < -X_VELOCITY_MAX) {
		xVelocity = -X_VELOCITY_MAX;
	}	
	xPos += xVelocity;
	yPos -= yVelocity;
	if (!Collide()) {
		yVelocity -= GRAVITY;
	}
	++frame;
}

//Displays the current sprite
void AnimCharacter::Display() {
	//probably combine these later
	projectile.Update(frame);
	projectile.Display(frame);
	sprites->DisplayText("Player 1", xPos, yPos - SPRITE_HEIGHT);
	if (spriteSheet.Display(xPos, yPos, frame, currentSprite)) {
		FinishAnimation();
	}
}


/* Corrects the character's position if it has collided with something in the environment
*/
bool AnimCharacter::Collide() {
	const int LEFT = xPos;
	const int RIGHT = xPos + STAND_SPRITE_WIDTH;
	const int TOP = yPos;
	const int BOTTOM = yPos + SPRITE_HEIGHT;
	bool collided = false;

	if (xPos < X_MIN) { xPos = X_LIMIT; }
	if (xPos > X_LIMIT) { xPos = X_MIN; }

	SDL_Rect leftBottom = sprites->IsIn("PLATFORM", LEFT, BOTTOM);
	SDL_Rect rightBottom = sprites->IsIn("PLATFORM", RIGHT, BOTTOM);
	SDL_Rect leftTop = sprites->IsIn("PLATFORM", LEFT, TOP);
	SDL_Rect rightTop = sprites->IsIn("PLATFORM", RIGHT, TOP);

	if (yPos > WINDOW_HEIGHT - SPRITE_HEIGHT
	 || (leftBottom.w && rightBottom.w)) {
		if (leftBottom.w) {
			Floor(leftBottom.y - SPRITE_HEIGHT);
		}
		else {
			Floor(WINDOW_HEIGHT - SPRITE_HEIGHT);
		}
		collided = true;
	}
	else if (rightTop.w && leftTop.w) {
		yVelocity = 0;
		yPos = leftTop.y + leftTop.h;
	}
	else if (rightTop.w && rightBottom.w) {
		xVelocity = 0;
		xPos = rightTop.x - STAND_SPRITE_WIDTH;
	}
	else if (leftTop.w && leftBottom.w) {
		xVelocity = 0;
		xPos = leftTop.x + leftTop.w;
	}
	else if (leftTop.w) {
		xVelocity = 0;
		xPos = leftTop.x + leftTop.w;
	}
	else if (rightTop.w) {
		xVelocity = 0;
		xPos = rightTop.x;
	}
	else if (rightBottom.w) {
		xVelocity = 0;
		xPos = rightBottom.x - STAND_SPRITE_WIDTH;
	}
	else if (leftBottom.w) {
		xVelocity = 0;
		xPos = leftBottom.x + leftBottom.w;
	}
	return collided;

}

/* Shoots an aura sphere
*/
void AnimCharacter::Attack() {
	const int PROJECTILE_OFFSET = 10;
	bool direction = false;
	previousSprite = currentSprite;
	if (currentSprite == WALK_RIGHT
		|| currentSprite == STAND_RIGHT
		|| currentSprite == JUMP_RIGHT
		|| currentSprite == DUCK_RIGHT) {
		currentSprite = ATTACK_RIGHT;
		direction = true;
	}
	else {
		currentSprite = ATTACK_LEFT;
		direction = false;
	}
		projectile.Start(xPos - PROJECTILE_OFFSET, yPos, direction, previousSprite);
	frame = 0;
}

/* called when the character hits a floor to correct their y position to be 
	on top of the floor
*/
void AnimCharacter::Floor(int height) {
		jump = false;
		yVelocity = 0;
		yPos = height;
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

}

/* Returns to the previous animation when an animation completes
*/

void AnimCharacter::FinishAnimation() {
	std::swap(currentSprite, previousSprite);
}


}

#include "Character.h"

#include <iostream>
using std::cout;
using std::endl;
namespace game {

Character::Character(ImageLibrary& initLibrary, SpriteSheet& sheet):
	currentSprite(STAND_RIGHT),
	previousSprite(STAND_RIGHT),
	jump(false),
	xPos(0),
	yPos(0),
	xVelocity(0),
	yVelocity(0),
	frame(0),
	sprites(sheet),
	library(initLibrary) {}

Character::Character(const Character& toCopy):
	currentSprite(STAND_RIGHT),
	previousSprite(STAND_RIGHT),
	jump(false),
	xPos(0),
	yPos(0),
	xVelocity(0),
	yVelocity(0),
	frame(0),
	sprites(toCopy.sprites),
	library(toCopy.library) {
	}
/* Moves the character right
 */
void Character::MoveRight() {
	if (xVelocity < 0) {
		xVelocity = 0;
	}
	currentSprite = WALK_RIGHT;
}

/* Moves the Character Left
 */
void Character::MoveLeft() {
	if (xVelocity > 0) {
		xVelocity = 0;
	}
	currentSprite = WALK_LEFT;
}

/* Plays the idle animation for the character
 */
void Character::Idle(){
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


/* Tests if the character collides
 */
bool Character::Collide(){
	const int LEFT = xPos;
	const int RIGHT = xPos + GetWidth();
	const int TOP = yPos;
	const int BOTTOM = yPos + GetHeight();
	bool collided = false;

	if (xPos < X_MIN) { xPos = X_LIMIT; }
	if (xPos > X_LIMIT) { xPos = X_MIN; }
	SDL_Rect leftBottom = library.IsIn("PLATFORM", LEFT, BOTTOM);
	SDL_Rect rightBottom = library.IsIn("PLATFORM", RIGHT, BOTTOM);
	SDL_Rect leftTop = library.IsIn("PLATFORM", LEFT, TOP);
	SDL_Rect rightTop = library.IsIn("PLATFORM", RIGHT, TOP);

	if (yPos > WINDOW_HEIGHT - GetHeight()
	 || (leftBottom.w && rightBottom.w)) {
		if (leftBottom.w) {
			Floor(leftBottom.y - GetHeight());
		}
		else {
			Floor(WINDOW_HEIGHT - GetHeight());
		}
		collided = true;
	}
	else if (rightTop.w && leftTop.w) {
		yVelocity = 0;
		yPos = leftTop.y + leftTop.h;
	}
	else if (rightTop.w && rightBottom.w) {
		xVelocity = 0;
		xPos = rightTop.x - GetWidth();
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
		xPos = rightBottom.x - GetWidth();
	}
	else if (leftBottom.w) {
		xVelocity = 0;
		xPos = leftBottom.x + leftBottom.w;
	}
	return collided;
 }


/* Called to make the character stop on a floor
 */
void Character::Floor(int height){
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

/* Called to make a character stop on a wall
 */
void Character::Wall(int position){
}

/* called to make a character stop on a ceiling
 */ 
void Character::Ceiling(int height){
}

/* Updates the postion of the character
 */
void Character::UpdatePosition(){
	if (currentSprite == WALK_LEFT) {
		xVelocity -= GetXAcceleration();
	}
	else if (currentSprite == WALK_RIGHT) {
		xVelocity += GetXAcceleration();
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
		yVelocity -= GetGravity();
	}
	++frame;
}

/* Displays the sprite sheet of the character
 */
void Character::Display(){
	this->UpdatePosition();
	if (sprites.Display(xPos, yPos, frame, currentSprite)) {
		FinishAnimation();
	}
}
/* finishes a temporary action
 */
void Character::FinishAnimation() {
	std::swap(currentSprite, previousSprite);
}


}

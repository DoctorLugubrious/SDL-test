#include "Character.h"

namespace game {

	Character::Character():
		xPos(0),
		yPos(0),
		xVelocity(0),
		yVelocity(0),
		frame(0),
		currentSprite(STAND_RIGHT),
		previousSprite(STAND_RIGHT),
		sprites(NULL) {}


	void Character::MoveRight() {

	}

	void Character::MoveLeft(){}
	void Character::Attack(){}
	void Character::Idle(){}
	bool Character::Collide(){ return false; }
	void Character::Floor(int height){}
	void Character::Wall(int position){}
	void Character::Ceiling(int height){}
	void Character::UpdatePosition(){}
	void Character::Display(){}

}

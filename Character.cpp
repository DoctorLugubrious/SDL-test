#include "Character.h"

namespace game {
	Character::Character(ImageLibrary* init) :
		xPos (0),
		yPos (0),
		width (60),
		height (48),
		sprites(init) {};

	void Character::MoveRight() {
		sprites->Display("RIGHT");
	}

	void Character::MoveLeft() {
		sprites->Display("LEFT");
	}

	void Character::Jump() {
		sprites->Display("UP");
	}
	
	void Character::Duck() {
		sprites->Display("DOWN");
	}
	
	void Character::Idle() {
		sprites->Display("NEUTRAL");
	}
}

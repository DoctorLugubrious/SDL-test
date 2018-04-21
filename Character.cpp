#include "Character.h"

namespace game {
	const int X_LIMIT = 620;
	const int Y_LIMIT = 480;
	const int X_MIN = -50;
	
	Character::Character(ImageLibrary* init) :
		xPos (0),
		yPos (0),
		width (60),
		height (48),
		sprites(init) {};

	void Character::MoveRight() {
		xPos += 10;
		if (xPos > X_LIMIT) { xPos = X_MIN; }
		sprites->Display("RIGHT", xPos, yPos);
	}

	void Character::MoveLeft() {
		xPos -= 10;
		if (xPos < X_MIN) { xPos = X_LIMIT; }
		sprites->Display("LEFT", xPos, yPos);
	}

	void Character::Jump() {
		sprites->Display("UP", xPos, yPos);
	}
	
	void Character::Duck() {
		sprites->Display("DOWN", xPos, yPos);
	}
	
	void Character::Idle() {
		sprites->Display("NEUTRAL", xPos, yPos);
	}
}

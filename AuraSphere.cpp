#include "AuraSphere.h"
#include "constants.h"
#include <iostream>
using std::cout;
using std::endl;
namespace game {

const int DELAY = 11;
const int SPEED = 20;

/* Initializes the data of the aura sphere
*/
AuraSphere::AuraSphere(CharacterSpriteSheet* init):
	active(false), 
	direction(true),
	xPos(0),
	yPos(0),
	delay(DELAY),
	frame(0),
	images(init) {};


/* tells the auraSphere to start moving
*/
void AuraSphere::Start(int x, int y, bool left, CharacterState state) {
	xPos = x;
	yPos = y;
	active = true;
	direction = left;
	if (state == WALK_LEFT || state == WALK_RIGHT) {
		delay = 0;
	}
	else {
		delay = DELAY;
	}
}

/* Renders the Aura Sphere on the current renderer
*/ 
void AuraSphere::Display(int frame) {
	if (frame < delay) { return; }
	if (xPos <= X_MIN || xPos >= X_LIMIT) {
		active = false;
	}
	if (active) {
		if (direction) {
			images->Display(xPos, yPos, frame, AURA_SPHERE_RIGHT);
		}
		else {
			images->Display(xPos, yPos, frame, AURA_SPHERE_LEFT);
		}
	}
}

/*Updates the aura sphere's position on the screen
*/
void AuraSphere::Update(int frame) {
	if (frame < delay) { return; }
	if (active) {
		if(direction) {
			xPos += SPEED;
		}
		else {
			xPos -= SPEED;
		}
	}
}
}


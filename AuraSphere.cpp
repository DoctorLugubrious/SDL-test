#include "AuraSphere.h"
#include "constants.h"
#include <iostream>
using std::cout;
using std::endl;
namespace game {

/* Initializes the data of the aura sphere
*/
AuraSphere::AuraSphere(CharacterSpriteSheet* init):
	active(false), 
	direction(true),
	xPos(0),
	yPos(0),
	frame(0),
	images(init) {};


/* tells the auraSphere to start moving
*/
void AuraSphere::Start(int x, int y, bool left) {
	xPos = x;
	yPos = y;
	active = true;
	direction = left;
}

/* Renders the Aura Sphere on the current renderer
*/ 
void AuraSphere::Display(int frame) {
	if (frame < 11) { return; }
	if (xPos <= X_MIN || xPos >= X_LIMIT) {
		active = false;
	}
	if (active) {
		if (direction) {
			images->Display(xPos, yPos, frame, AURA_SPHERE_LEFT);
		}
		else {
			images->Display(xPos, yPos, frame, AURA_SPHERE_RIGHT);
		}
	}
}

/*Updates the aura sphere's position on the screen
*/
void AuraSphere::Update(int frame) {
	if (frame < 11) { return; }
	if (active) {
		if(direction) {
			xPos += 7;
		}
		else {
			xPos -= 7;
		}
	}
}
}


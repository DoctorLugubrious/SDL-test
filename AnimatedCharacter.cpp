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
AnimCharacter::AnimCharacter(ImageLibrary& init, EnemyHorde& horde) :
	Character(init, spriteSheet),
	sprites(init),
	enemies(horde),
	projectiles(),
	spriteSheet(sprites) {};
//lets the character jump
void AnimCharacter::Jump() {
	if (!Character::jump) {
		yVelocity += Y_ACCELERATION;
		jump = true;
		if (xVelocity > 0) {
			currentSprite = JUMP_RIGHT;
		}
		else {
			currentSprite = JUMP_LEFT;
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
//Displays the current sprite
void AnimCharacter::Display() {
	for (AuraSphere& projectile : projectiles) {
		projectile.Display(frame);
		enemies.AttackAt(projectile.GetX(), projectile.GetY());
	}
	if (!projectiles.empty() && !projectiles.back().Active()) {
		projectiles.pop_back();
	}
	sprites.DisplayText("Player 1", xPos, yPos - SPRITE_HEIGHT);
	Character::Display();
}
/* Shoots an aura sphere
*/
void AnimCharacter::Attack() {
	const int PROJECTILE_OFFSET = 10;
	bool direction = false;
	if (currentSprite == WALK_RIGHT
		|| currentSprite == STAND_RIGHT
		|| currentSprite == JUMP_RIGHT
		|| currentSprite == DUCK_RIGHT) {
		previousSprite = currentSprite;
		currentSprite = ATTACK_RIGHT;
		direction = true;
		projectiles.push_front(AuraSphere(&spriteSheet));
		projectiles.front().Start(xPos - PROJECTILE_OFFSET, yPos, direction, previousSprite);
		frame = 0;
	}
	else if (currentSprite != ATTACK_RIGHT 
		&& currentSprite != ATTACK_LEFT) {
		previousSprite = currentSprite;
		currentSprite = ATTACK_LEFT;
		direction = false;
		projectiles.push_front(AuraSphere(&spriteSheet));
		projectiles.front().Start(xPos - PROJECTILE_OFFSET, yPos, direction, previousSprite);
		frame = 0;
	}
}


}

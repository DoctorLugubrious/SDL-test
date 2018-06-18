#include <iostream>
#include "Enemy.h"
#include "AnimatedCharacter.h"
using std::cout;
using std::endl;

namespace game {

/*
 *The Enemy class needs an ImageLibrary pointer to
 *display images, but other than that, takes care of itself.
 */ 	
Enemy::Enemy(ImageLibrary& init) :
	Character(init, spriteSheet),
	sprites(init),
	spriteSheet(sprites) {};
/* Attacks
*/
void Enemy::Attack() {
	if (currentSprite == WALK_RIGHT
		|| currentSprite == STAND_RIGHT
		|| currentSprite == JUMP_RIGHT
		|| currentSprite == DUCK_RIGHT) {
		previousSprite = currentSprite;
		currentSprite = ATTACK_RIGHT;
		frame = 0;
	}
	else if (currentSprite != ATTACK_RIGHT 
		&& currentSprite != ATTACK_LEFT) {
		previousSprite = currentSprite;
		currentSprite = ATTACK_LEFT;
		frame = 0;
	}
}

void Enemy::Attack(AnimCharacter& player) {
	Attack();
	if (player.IsIn(xPos, yPos)) {
		player.Die();
	}
}


}

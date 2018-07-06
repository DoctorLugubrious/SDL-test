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
	if (GetState() == WALK_RIGHT
		|| GetState() == STAND_RIGHT
		|| GetState() == JUMP_RIGHT
		|| GetState() == DUCK_RIGHT) {
		SetState(DUCK_ATTACK_RIGHT, GetState());
		ResetFrame();
	}
	else if (GetState() != DUCK_ATTACK_RIGHT 
		&& GetState() != DUCK_ATTACK_LEFT) {
		SetState(DUCK_ATTACK_LEFT, GetState());
		ResetFrame();
	}
}

void Enemy::Attack(AnimCharacter& player) {
	Attack();
	if (player.IsIn(GetX(), GetY())) {
		player.Die();
	}
}


}

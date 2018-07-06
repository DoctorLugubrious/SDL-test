#include <iostream>
#include <algorithm>

#include "constants.h"
#include "AnimatedCharacter.h"

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
	if (!GetJump()) {
		SetYVelocity(GetYVelocity() + Y_ACCELERATION);
		SetJump(true);
		if (GetXVelocity() > 0) {
			SetState(JUMP_RIGHT);
		}
		else {
			SetState(JUMP_LEFT);
		}
		ResetFrame();
	}
}

//ducks the character, which makes them fall faster
void AnimCharacter::Duck() {
	if (GetState() == WALK_RIGHT 
		||GetState() == STAND_RIGHT
		||GetState() == DUCK_RIGHT
		||GetState() == JUMP_RIGHT
	) {
		SetState(DUCK_RIGHT);
	}
	else {
		SetState(DUCK_LEFT);
	}
	SetXVelocity(0);
	SetYVelocity(GetYVelocity() - GRAVITY);
}
//Displays the current sprite
void AnimCharacter::Display() {
	if (Dead()) {
		sprites.DisplayText("GAME OVER", WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
		return;
	}
	for (AuraSphere& projectile : projectiles) {
		projectile.Display(GetFrame());
		enemies.AttackAt(projectile.GetX(), projectile.GetY());
	}
	if (!projectiles.empty() && !projectiles.back().Active()) {
		projectiles.pop_back();
	}
	if(GetState() == DUCK_ATTACK_LEFT
	|| GetState() == DUCK_ATTACK_RIGHT) {
		enemies.AttackAt(GetX(), GetY());
	}
	sprites.DisplayText("Player 1", GetX(), GetY() - SPRITE_HEIGHT);
	Character::Display();
}
/* Shoots an aura sphere
*/
void AnimCharacter::Attack() {
	const int PROJECTILE_OFFSET = 10;
	bool direction = false;
	if (GetState() == WALK_RIGHT
		|| GetState() == STAND_RIGHT) {
		SetState(RANGED_ATTACK_RIGHT, GetState());
		direction = true;
		projectiles.push_front(AuraSphere(&spriteSheet));
		projectiles.front().Start(GetX() - PROJECTILE_OFFSET, GetY(), direction, pGetState());
		ResetFrame();		
	}
	else if (GetState() == DUCK_LEFT) {
		ResetFrame();		
		SetState(DUCK_ATTACK_LEFT, GetState());
	}
	else if (GetState() == DUCK_RIGHT) {
		ResetFrame();		
		SetState(DUCK_ATTACK_RIGHT, GetState());
	}
	else if (GetState() == JUMP_LEFT) {
		ResetFrame();		
		SetState(AIR_ATTACK_LEFT, GetState());
	}
	else if (GetState() == JUMP_RIGHT) {
		ResetFrame();		
		SetState(AIR_ATTACK_RIGHT, GetState());
	}
	else if (GetState() != RANGED_ATTACK_RIGHT 
		&& GetState() != RANGED_ATTACK_LEFT) {
		SetState(RANGED_ATTACK_LEFT, GetState());
		direction = false;
		projectiles.push_front(AuraSphere(&spriteSheet));
		projectiles.front().Start(GetX() - PROJECTILE_OFFSET, GetY(), direction, pGetState());
		ResetFrame();		
	}
}


}

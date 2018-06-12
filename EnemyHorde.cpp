#include "EnemyHorde.h"
#include "AnimatedCharacter.h"
#include <iostream>
namespace game {
void EnemyHorde::Display(int x, int y) {
	if (theHorde.empty()) {
		theHorde.push_back(Enemy(images));
	}
	for (Enemy& enemy : theHorde) {
		int diff = enemy.GetX() - player.GetX();
		if (diff < -60) {
			enemy.MoveRight();
		}
		else if (diff > 60) {
			enemy.MoveLeft();
		}
		else {
			enemy.Attack();
		}
		enemy.Display();
	}
}

bool EnemyHorde::AttackAt(int x, int y) {
	//for enemy in horde
		//if hit, 
			//remove from horde
			//return true
	return false;
}


}


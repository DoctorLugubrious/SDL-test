#include <iostream>
#include <sstream>

#include "AnimatedCharacter.h"
#include "EnemyHorde.h"
#include "constants.h"
namespace game {
void EnemyHorde::Display(int x, int y) {
	std::ostringstream os;
	os << "Kills: " << numKills;
	images.DisplayText(os.str(), WINDOW_WIDTH, 30);
	if (theHorde.empty()) {
		hordeCompleted = 0;
		nextWaveSize++;
	}
	if (theHorde.size() < nextWaveSize && hordeCompleted != nextWaveSize) {
		theHorde.push_back(Enemy(images));
		theHorde.back().SetPos(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
		++hordeCompleted;
	}
	auto it = theHorde.begin();
	for (; it != theHorde.end(); ++it) {
		if (it->Dead()) {
			auto temp = it;
			temp--;
			theHorde.erase(it);
			it = temp;
			++numKills;
			continue;
		}
		int diff = it->GetX() - player.GetX();
		if (diff < -60) {
			it->MoveRight();
		}
		else if (diff > 60) {
			it->MoveLeft();
		}
		else {
			it->Attack(player);
		}
		it->Display();
	}
}

bool EnemyHorde::AttackAt(int x, int y) {
	for(Enemy& enemy: theHorde) {
		if (enemy.IsIn(x,y)) {
			enemy.Die();
			return true;
		}
			//remove from horde
			//return true
	}
	return false;
}


}


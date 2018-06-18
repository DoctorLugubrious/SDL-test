#ifndef ENEMY_HORDE_DOT_H_
#define ENEMY_HORDE_DOT_H_

#include <list>
#include <time.h>
#include "Enemy.h"

namespace game {

class AnimCharacter;

/* The Enemy Horde class is a class that contains enemies. It controls what they do 
 * and spawns them when necessary.
 ***EnemyHorde(ImageLibrary&, AnimCharacter&)
 ***	Needs an Image library and animated character to display images and fight.
 ***Display(int x, int y)
 ***	updates the enemies based on the player's position
 ***AttackAt(int x, int y)
 ***	sees if any enemies are hit by the attack and damages them accordingly
 */

class EnemyHorde {
public:
	EnemyHorde(ImageLibrary& initImage, AnimCharacter& initPlayer):
		hordeCompleted(0),
		numKills(0),
		nextWaveSize(0),
		images(initImage),
		player(initPlayer) {
			srand(time(0));
		};
	void Display(int x, int y);
	bool AttackAt(int x, int y);
private:
	int hordeCompleted;
	
	int numKills;

	int nextWaveSize;

	ImageLibrary& images;
	AnimCharacter& player;

	std::list<Enemy> theHorde;
};

}

#endif

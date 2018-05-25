#ifndef AURA_SPHERE_DOT_H_
#define AURA_SPHERE_DOT_H_

#include "constants.h"
#include "CharacterSpriteSheet.h"

/*The Aura Sphere class is a projectile that an animated character attacks with.
 *it moves across the screen until it reaches the edge.
 ***AuraSphere(CharacterSpriteSheet*)
 ***	The Aura Sphere constructor needs a character sprite sheet pointer to be able to display images.
 ***Start(int x, int y, bool left)
 ***	This starts the aura sphere's path at the point (x,y). It moves left if the last argument is true
 ***	and right otherwise.
 ***Update(int frame)
 ***	Updates the position given the frame number of the current animation.
 ***Display(int frame)
 ***	Displays the aura sphere at the currrent position given the frame of the animation.
 */

namespace game {
class AuraSphere {
public:
	AuraSphere(CharacterSpriteSheet*);
	void Start(int x, int y, bool left, CharacterState state);
	void Update(int frame);
	void Display(int frame);
private:
	bool active;
	bool direction;	

	int xPos;
	int yPos;
	int delay;
	size_t frame;

	CharacterSpriteSheet* images;
};
}

#endif

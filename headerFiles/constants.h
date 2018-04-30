#ifndef CONSTANTS_DOT_H_
#define CONSTANTS_DOT_H_
	
const int WINDOW_WIDTH = 1000;
const int WINDOW_HEIGHT = 800;

const int X_LIMIT = WINDOW_WIDTH - 20;
const int Y_LIMIT = WINDOW_HEIGHT;
const int X_MIN = -50;
const int X_ACCELERATION = 3;
const int Y_ACCELERATION = 35;

const int X_VELOCITY_MAX = 10;
const int Y_VELOCITY_MAX = 100;

const int GRAVITY = 2;

static const int WALK_SPRITE_WIDTH = 57;
static const int STAND_SPRITE_WIDTH = 37;
static const int SPRITE_HEIGHT = 57;

enum CharacterState { STAND_LEFT, STAND_RIGHT, WALK_LEFT, WALK_RIGHT, JUMP, DUCK_LEFT, DUCK_RIGHT };

#endif

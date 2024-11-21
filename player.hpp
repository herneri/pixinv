#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

#include <raylib.h>
#include "constants.hpp"

class Player {
public:
	int x;
	int y;
	int speed;

	float radius;
	Color color;

	Player() {
		this->x = SCREEN_WIDTH / 2;
		this->y = SCREEN_HEIGHT - (SCREEN_HEIGHT / (SCREEN_HEIGHT / 100));
		this->speed = 5;
		this->radius = 20;
		this->color = WHITE;
	}
};

#endif /* PIXINV_PLAYER_H */

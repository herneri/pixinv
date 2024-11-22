#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

#include <raylib.h>
#include "constants.hpp"
#include "laser.hpp"

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

	void shoot(void) {
		if (Laser::lasers.size() > 10) {
			return;
		}

		Laser *new_laser = new Laser(this->x, this->y - 50);
		Laser::lasers.push_back(new_laser);
		return;
	}
};

#endif /* PIXINV_PLAYER_H */

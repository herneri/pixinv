#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

#include <raylib.h>
#include "constants.hpp"
#include "laser.hpp"

class Player {
public:
	Vector2 posistion;
	int speed;

	float radius;
	Color color;

	Player() {
		this->posistion.x = SCREEN_WIDTH / 2;
		this->posistion.y = SCREEN_HEIGHT - (SCREEN_HEIGHT / (SCREEN_HEIGHT / 100));
		this->speed = 5;
		this->radius = 20;
		this->color = WHITE;
	}

	void shoot(void) {
		if (Laser::lasers.size() > 10) {
			return;
		}

		Laser *new_laser = new Laser(this->posistion.x, this->posistion.y - 50, true);
		Laser::lasers.push_back(new_laser);
		return;
	}
};

#endif /* PIXINV_PLAYER_H */

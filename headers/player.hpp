#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

#include <vector>

#include "laser.hpp"

class Player {
public:
	Vector2 posistion;
	int speed;

	float radius;
	Color color;

	Player();

	void shoot(std::vector<Laser *> &lasers);
};

#endif /* PIXINV_PLAYER_H */

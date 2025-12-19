#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

#include <vector>

#include "entity.hpp"
#include "laser.hpp"

class Player : public Entity {
private:
	float radius;
	Color color;

public:
	Player();

	const int get_radius(void) const;
};

#endif /* PIXINV_PLAYER_H */

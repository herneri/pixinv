/* Entity.hpp: Superclass that Player and Enemy objects inherit. */

#ifndef PIXINV_ENTITY_H
#define PIXINV_ENTITY_H

#include <raylib.h>
#include <vector>

#include "laser.hpp"

class Entity {
private:
	Vector2 posistion;

	int height;
	int length;

	int speed;

protected:
	/* Modifiers for posistion. */
	void set_x(const int x);
	void set_y(const int y);

	void set_speed(const unsigned int speed);

public:
	/* Accessors meant for use during screen drawing. */
	const Vector2 &get_posistion(void) const;
	const int get_height(void) const;
	const int get_length(void) const;

	/* Modifiers for horizontal movement. */
	void move_left(void);
	void move_right(void);

	void shoot(std::vector<Laser> &lasers, const int laser_count_threshold, const bool is_player) const;
};

#endif /* PIXINV_ENTITY_H */

#ifndef PIXINV_LASER_H
#define PIXINV_LASER_H

#include <vector>

class Laser {
private:
	int width;
	int length;

public:
	Vector2 posistion;

	bool is_shooter_player;

	Laser(int x, int y, bool is_shooter_player);

	int get_width(void);
	int get_length(void);
};

void draw_lasers(std::vector<Laser *> &lasers);

#endif /* PIXINV_LASER_H */

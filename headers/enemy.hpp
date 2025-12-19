#ifndef PIXINV_ENEMY_H
#define PIXINV_ENEMY_H

#include <queue>
#include "constants.hpp"

const int ROWS = 3;
const int COLUMNS = 4;

struct enemy_index {
	int row;
	int column;
};

const int enemy_x_posistion[] {
	SCREEN_WIDTH - 650, SCREEN_WIDTH - 475,
	SCREEN_WIDTH - 300, SCREEN_WIDTH - 150
};

const int enemy_y_posistion[] {
	SCREEN_HEIGHT / 12, SCREEN_HEIGHT / 6,
	SCREEN_HEIGHT / 4
};

class Enemy : public Entity {
private:
	float radius;

public:
	Enemy(int x, int y);

	float get_radius(void);
};

void enemy_grid_init(void);
void draw_enemies(void);
void random_enemy_shoot(std::vector<Laser> &lasers);

#endif /* PIXINV_ENEMY_H */

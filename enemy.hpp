#ifndef PIXINV_ENEMY_H
#define PIXINV_ENEMY_H

#include <raylib.h>
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

class Enemy {
private:
	float radius;
public:
	Vector2 posistion;

	static Enemy *enemy_grid[ROWS][COLUMNS];
	static std::queue<struct enemy_index *> dead_enemy_indexes;

	Enemy(int x, int y) {
		this->posistion.x = x;
		this->posistion.y = y;
		this->radius = 20;
	}

	static void enemy_grid_init(void) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				enemy_grid[i][j] = new Enemy(enemy_x_posistion[j], enemy_y_posistion[i]);
			}
		}

		return;
	}

	static void draw_enemies(void) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				Enemy *current_enemy = enemy_grid[i][j];
				if (current_enemy == nullptr)
					continue;

				DrawCircle(current_enemy->posistion.x, current_enemy->posistion.y, current_enemy->radius, GREEN);
			}
		}

		return;
	}
};

Enemy *Enemy::enemy_grid[ROWS][COLUMNS];
std::queue<struct enemy_index *> Enemy::dead_enemy_indexes;

#endif /* PIXINV_ENEMY_H */

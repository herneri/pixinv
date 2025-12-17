#include <raylib.h>
#include <queue>

#include "../headers/enemy.hpp"
#include "../headers/constants.hpp"

Enemy *enemy_grid[ROWS][COLUMNS];
std::queue<struct enemy_index *> dead_enemy_indexes;

Enemy::Enemy(int x, int y) {
	this->posistion.x = x;
	this->posistion.y = y;
	this->radius = 20;
}

float Enemy::get_radius(void) {
	return this->radius;
}

void enemy_grid_init(void) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			enemy_grid[i][j] = new Enemy(enemy_x_posistion[j], enemy_y_posistion[i]);
		}
	}

	return;
}

void draw_enemies(void) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			Enemy *current_enemy = enemy_grid[i][j];
			if (current_enemy == nullptr)
				continue;

			DrawCircle(current_enemy->posistion.x, current_enemy->posistion.y, current_enemy->get_radius(), GREEN);
		}
	}

	return;
}

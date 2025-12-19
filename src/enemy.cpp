#include <raylib.h>
#include <ctime>
#include <cstdlib>
#include <queue>

#include "../headers/entity.hpp"
#include "../headers/enemy.hpp"
#include "../headers/constants.hpp"

Enemy *enemy_grid[ROWS][COLUMNS];
std::queue<struct enemy_index *> dead_enemy_indexes;

Enemy::Enemy(int x, int y) {
	this->set_x(x);
	this->set_y(y);
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

			const Vector2 &enemy_posistion = current_enemy->get_posistion();

			DrawCircle(enemy_posistion.x, enemy_posistion.y, current_enemy->get_radius(), GREEN);
		}
	}

	return;
}

void random_enemy_shoot(std::vector<Laser> &lasers) {
	if (lasers.size() > 15) {
		return;
	}

	srand(time(0));
	int random_i = rand() % ROWS;
	int random_j = rand() % COLUMNS;

	enemy_grid[random_i][random_j]->shoot(lasers, 15, false);
	return;
}

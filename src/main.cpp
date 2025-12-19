#include <iostream>

#include <ctime>
#include <raylib.h>

#include "../headers/laser.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include "../headers/constants.hpp"

int main() {
	Player p1 = Player();
	enemy_grid_init();
	std::vector<Laser> lasers;

	const float PLAYER_SHOOT_COOLDOWN = 0.02;
	const float ENEMY_SHOOT_COOLDOWN = 0.1;

	clock_t player_shoot_timeout = clock();
	clock_t enemy_shoot_timeout = clock();

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		Vector2 p1_vector = p1.get_posistion();

		if (IsKeyDown(KEY_RIGHT)) {
			p1.move_right();
		} else if (IsKeyDown(KEY_LEFT)) {
			p1.move_left();
		} else if (IsKeyDown(KEY_SPACE) && ( (float) (clock() - player_shoot_timeout) / CLOCKS_PER_SEC) > PLAYER_SHOOT_COOLDOWN) {
			p1.shoot(lasers, 10, true);
			player_shoot_timeout = clock();
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(p1_vector.x, p1_vector.y, p1.get_radius(), WHITE);
		draw_enemies();

		if (( (float) (clock() - enemy_shoot_timeout) / CLOCKS_PER_SEC) > ENEMY_SHOOT_COOLDOWN) {
			random_enemy_shoot(lasers);
			enemy_shoot_timeout = clock();
		}

		draw_lasers(lasers);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

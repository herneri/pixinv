#include <iostream>
#include <raylib.h>

#include "../headers/laser.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include "../headers/constants.hpp"

int main() {
	Player p1 = Player();
	enemy_grid_init();
	std::vector<Laser> lasers;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		Vector2 p1_vector = p1.get_posistion();

		if (IsKeyDown(KEY_RIGHT)) {
			p1.move_right();
		} else if (IsKeyDown(KEY_LEFT)) {
			p1.move_left();
		} else if (IsKeyDown(KEY_SPACE)) {
			p1.shoot(lasers, 10, true);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(p1_vector.x, p1_vector.y, p1.get_radius(), WHITE);
		draw_enemies();
		random_enemy_shoot(lasers);
		draw_lasers(lasers);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

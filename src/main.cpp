#include <iostream>
#include <raylib.h>

#include "../headers/laser.hpp"
#include "../headers/player.hpp"
#include "../headers/enemy.hpp"
#include "../headers/constants.hpp"

int main() {
	Player p1 = Player();
	enemy_grid_init();
	std::vector<Laser *> lasers;

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		if (IsKeyDown(KEY_RIGHT)) {
			p1.posistion.x += p1.speed;
		} else if (IsKeyDown(KEY_LEFT)) {
			p1.posistion.x -= p1.speed;
		} else if (IsKeyDown(KEY_SPACE)) {
			p1.shoot(lasers);
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(p1.posistion.x, p1.posistion.y, p1.radius, WHITE);
		draw_enemies();
		draw_lasers(lasers);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

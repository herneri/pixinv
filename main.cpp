#include <iostream>
#include <raylib.h>

#include "laser.hpp"
#include "player.hpp"
#include "constants.hpp"

int main() {
	Player p1 = Player();

	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		if (IsKeyDown(KEY_RIGHT)) {
			p1.x += p1.speed;
		} else if (IsKeyDown(KEY_LEFT)) {
			p1.x -= p1.speed;
		} else if (IsKeyDown(KEY_SPACE)) {
			p1.shoot();
		}

		BeginDrawing();
		ClearBackground(BLACK);

		DrawCircle(p1.x, p1.y, p1.radius, WHITE);
		Laser::draw_lasers();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}

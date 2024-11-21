#include <iostream>
#include <raylib.h>
#include "constants.hpp"
#include "player.hpp"

int main() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	SetTargetFPS(60);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(GREEN);
		EndDrawing;
	}

	CloseWindow();
	return 0;
}

#include <raylib.h>

#include <vector>
#include <string>

#include "../headers/laser.hpp"
#include "../headers/constants.hpp"

Laser::Laser(int x, int y, bool is_shooter_player) {
	this->posistion.x = x;
	this->posistion.y = y;
	this->is_shooter_player = is_shooter_player;
	this->width = 5;
	this->length = 15;
}

int Laser::get_width(void) {
	return this->width;
}

int Laser::get_length(void) {
	return this->length;
}

void draw_lasers(std::vector<Laser> &lasers) {
	/*
	**	The lasers vector can change in size here,
	**	so always loop with the current size.
	*/
	for (int i = 0; i < lasers.size(); i++) {
		Laser &laser = lasers[i];

		if (laser.is_shooter_player == false) {
			if (laser.posistion.y >= 800) {
				lasers.erase(lasers.begin() + i);
				continue;
			}

			laser.posistion.y += 10;
		} else {
			if (laser.posistion.y <= 0) {
				lasers.erase(lasers.begin() + i);
				continue;
			}

			laser.posistion.y -= 10;
		}

		DrawRectangle(laser.posistion.x, laser.posistion.y, laser.get_width(), laser.get_length(), RED);
	}
}

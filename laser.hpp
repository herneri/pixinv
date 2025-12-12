#ifndef PIXINV_LASER_H
#define PIXINV_LASER_H

#include <raylib.h>
#include <vector>
#include <string>
#include "constants.hpp"

class Laser {
private:
	int width;
	int length;

public:
	Vector2 posistion;

	static std::vector<Laser *> lasers;

	bool is_shooter_player;

	Laser(int x, int y, bool is_shooter_player) {
		this->posistion.x = x;
		this->posistion.y = y;
		this->is_shooter_player = is_shooter_player;
		this->width = 5;
		this->length = 15;
	}

	static void draw_lasers() {
		/*
		**	The lasers vector can change in size here,
		**	so always loop with the current size.
		*/
		for (int i = 0; i < lasers.size(); i++) {
			Laser *laser = lasers[i];

			if (laser->posistion.y <= 0) {
				lasers.erase(lasers.begin() + i);
				continue;
			}

			laser->posistion.y -= 10;
			DrawRectangle(laser->posistion.x, laser->posistion.y, laser->width, laser->length, RED);
		}
	}
};

std::vector<Laser *> Laser::lasers;

#endif /* PIXINV_LASER_H */

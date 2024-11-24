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

	std::string shooter;

	Laser(int x, int y, std::string shooter) {
		this->posistion.x = x;
		this->posistion.y = y;
		this->shooter = shooter;
		this->width = 5;
		this->length = 15;
	}

	static void draw_lasers() {
		int length = lasers.size();

		for (int i = 0; i < length; i++) {
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

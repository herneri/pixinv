#ifndef PIXINV_LASER_H
#define PIXINV_LASER_H

#include <vector>
#include "constants.hpp"

class Laser {
private:
	int width;
	int length;

public:
	int x;
	int y;

	static std::vector<Laser *> lasers;

	Laser(int x, int y) {
		this->x = x;
		this->y = y;
		this->width = 5;
		this->length = 15;
	}

	static void draw_lasers() {
		int length = lasers.size();

		for (int i = 0; i < length; i++) {
			Laser *laser = lasers[i];

			if (laser->y <= 0) {
				lasers.erase(lasers.begin() + i);
				continue;
			}

			laser->y -= 10;
			DrawRectangle(laser->x, laser->y, laser->width, laser->length, RED);
		}
	}
};

std::vector<Laser *> Laser::lasers;

#endif /* PIXINV_LASER_H */

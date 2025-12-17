#include <raylib.h>
#include <vector>

#include "../headers/player.hpp"
#include "../headers/constants.hpp"
#include "../headers/laser.hpp"

Player::Player() {
	this->posistion.x = SCREEN_WIDTH / 2;
	this->posistion.y = SCREEN_HEIGHT - (SCREEN_HEIGHT / (SCREEN_HEIGHT / 100));
	this->speed = 5;
	this->radius = 20;
	this->color = WHITE;
}

void Player::shoot(std::vector<Laser *> &lasers) {
	if (lasers.size() > 10) {
			return;
	}

	Laser *new_laser = new Laser(this->posistion.x, this->posistion.y - 50, true);
	lasers.push_back(new_laser);
	return;
}

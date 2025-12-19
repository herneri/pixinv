#include <raylib.h>
#include <vector>

#include "../headers/player.hpp"
#include "../headers/constants.hpp"
#include "../headers/laser.hpp"

Player::Player() {
	this->set_x(SCREEN_WIDTH / 2);
	this->set_y(SCREEN_HEIGHT - (SCREEN_HEIGHT / (SCREEN_HEIGHT / 100)));
	this->set_speed(5);
	this->radius = 20;
	this->color = WHITE;
}

const int Player::get_radius(void) const {
	return this->radius;
}

#include <raylib.h>

#include <vector>

#include "../headers/entity.hpp"
#include "../headers/laser.hpp"

void Entity::set_x(const int x) {
	this->posistion.x = x;
	return;
}

void Entity::set_y(const int y) {
	this->posistion.y = y;
	return;
}

void Entity::set_speed(const unsigned int speed) {
	this->speed = speed;
	return;
}

const Vector2 &Entity::get_posistion(void) const {
	return this->posistion;
}

const int Entity::get_height(void) const {
	return this->height;
}

const int Entity::get_length(void) const {
	return this->length;
}

void Entity::move_left(void) {
	this->posistion.x -= this->speed;
	return;
}

void Entity::move_right(void) {
	this->posistion.x += this->speed;
	return;
}

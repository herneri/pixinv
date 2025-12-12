#ifndef PIXINV_PLAYER_H
#define PIXINV_PLAYER_H

class Player {
public:
	Vector2 posistion;
	int speed;

	float radius;
	Color color;

	Player();

	void shoot(void);
};

#endif /* PIXINV_PLAYER_H */

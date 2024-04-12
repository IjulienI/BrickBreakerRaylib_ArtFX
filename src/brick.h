#ifndef BRICK_H
#define BRICK_H

#include <raylib.h>

class Brick
{
private:
	Vector2 position;
	Vector2 size;
	int life = 2;
	bool destroy = false;
	Color color = GREEN;
public:
	Brick(Vector2 postition, Vector2 size);
	~Brick();
	void Draw();
	void TakeDamage();
	bool GetDestoyed();
	Vector2 GetPosition();
	Vector2 GetSize();
};

#endif
#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>
#include "./constant.h"

class Paddle
{
private:
	Vector2 position;
	Vector2 size;
	Color color;
public:
	Paddle();
	Paddle(Vector2 position,Vector2 size, Color color);
	~Paddle();
	void Update(float dt);
	void Draw();

	Vector2 GetSize();
	Vector2 GetPosition();
};

#endif
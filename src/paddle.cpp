#include "paddle.h"


Paddle::Paddle()
{
}

Paddle::Paddle(Vector2 position, Vector2 size, Color color)
{
	this->position = position;
	this->size = size;
	this->color = color;
}

Paddle::~Paddle()
{
}

void Paddle::Update(float dt)
{
	if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && position.x + size.x < WINDOW_SIZE.x) {
		position.x += PADDLE_SPEED * dt;
	}
	if ((IsKeyDown(KEY_Q) || IsKeyDown(KEY_LEFT)) && position.x > 0) {
		position.x -= PADDLE_SPEED * dt;
	}
}

void Paddle::Draw()
{
	DrawRectangle(position.x, position.y, size.x, size.y, color);
}

Vector2 Paddle::GetSize()
{
	return size;
}

Vector2 Paddle::GetPosition()
{
	return position;
}

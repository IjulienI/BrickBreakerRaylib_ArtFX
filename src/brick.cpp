#include "brick.h"

Brick::Brick(Vector2 postition, Vector2 size)
{
	this->position = postition;
	this->size = size;
}

Brick::~Brick()
{
}

void Brick::Draw()
{
	if (!destroy) {
		DrawRectangle(position.x, position.y, size.x, size.y, color);
	}
}

void Brick::TakeDamage()
{
	life--;
	color = RED;
	if (life == 0) {
		destroy = true;
	}
}

bool Brick::GetDestoyed()
{
	return destroy;
}

Vector2 Brick::GetPosition()
{
	return position;
}

Vector2 Brick::GetSize()
{
	return size;
}

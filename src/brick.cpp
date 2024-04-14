#include "brick.h"

Brick::Brick(Vector2 postition, Vector2 size, GameManager* gameManager)
{
	this->position = postition;
	this->size = size;
	this->gameManager = gameManager;
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
	gameManager->AddScore(5);
	if (life == 0) {
		destroy = true;
		gameManager->AddScore(150);
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

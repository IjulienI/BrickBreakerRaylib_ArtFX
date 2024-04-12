#include "ball.h"

#include "./gameManager.h"


void Ball::WallCollision()
{
	if (position.x < radius) {
		velocity.x *= -1;
		position.x = radius;
	}
	else if (position.x + radius > WINDOW_SIZE.x) {
		velocity.x *= -1;
		position.x = WINDOW_SIZE.x - radius;
	}
	if (position.y < radius) {
		velocity.y *= -1;
		position.y = radius;
	}
	else if (position.y + radius > WINDOW_SIZE.y) {
		life--;
		velocity.y *= -1;
		velocity.x = 0;
		onPaddle = true;
	}
}

void Ball::PaddleCollision()
{
	if (position.y + radius > paddle->GetPosition().y && position.x - radius > paddle->GetPosition().x && position.x + radius < paddle->GetPosition().x + paddle->GetSize().x ) {
		float collisionLocation = position.x - (paddle->GetPosition().x + paddle->GetSize().x /2);
		float newVelocity = 1000 * collisionLocation / paddle->GetSize().x / 2;

		velocity.x = newVelocity;
		velocity.y *= -1;
	}
}

void Ball::Movement(float dt)
{
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;
}

void Ball::BrickCollision(Brick* brick)
{
	int xMinA = (int)position.x - radius;
	int yMinA = (int)position.y - radius;
	int xMaxA = (int)position.x + radius;
	int yMaxA = (int)position.y + radius;
	int xMinB = (int)brick->GetPosition().x;
	int yMinB = (int)brick->GetPosition().y;
	int xMaxB = (int)brick->GetPosition().x + brick->GetSize().x;
	int yMaxB = (int)brick->GetPosition().y + brick->GetSize().y;
	if (!(xMinB > xMaxA || yMinB > yMaxA || xMaxB < xMinA || yMaxB < yMinA)) {
		if (!brick->GetDestoyed()) {
			if (position.x - radius < brick->GetPosition().x) {
				brick->TakeDamage();
				position.x = brick->GetPosition().x - radius;
				velocity.x *= -1;
			}
			if (position.x + radius > brick->GetPosition().x + brick->GetSize().x) {
				brick->TakeDamage();
				position.x = brick->GetPosition().x + brick->GetSize().x + radius;
				velocity.x *= -1;
			}
			if (position.y - radius < brick->GetPosition().y) {
				brick->TakeDamage();
				position.y = brick->GetPosition().y - radius;
				velocity.y *= -1;
			}
			if (position.y + radius > brick->GetPosition().y + brick->GetSize().y) {
				brick->TakeDamage();
				position.y = brick->GetPosition().y + brick->GetSize().y + radius;
				velocity.y *= -1;
			}
		}
	}
}

void Ball::SetOnPaddle()
{
	onPaddle = true;
}

Ball::Ball(Vector2 position, Vector2 velocity, int radius, Color color)
{
	this->position = position;
	this->velocity = velocity;
	this->radius = radius;
	this->color = color;
}

Ball::~Ball()
{
}

void Ball::Init(Paddle* paddle)
{
	this->paddle = paddle;
}

void Ball::Update(float dt)
{
	if (!onPaddle) {
		Movement(dt);
		WallCollision();
		PaddleCollision();
	}
	else {
		position.x = paddle->GetPosition().x + paddle->GetSize().x / 2;
		position.y = paddle->GetPosition().y - 15;
		if (IsKeyPressed(KEY_E)) {
			onPaddle = false;
		}
	}
}

void Ball::Draw()
{
	DrawCircle(position.x, position.y, radius, color);
}

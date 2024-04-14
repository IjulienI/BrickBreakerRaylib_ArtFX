#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include <vector>
#include "./constant.h"
#include "./paddle.h"
#include "./brick.h"
#include "./gameManager.h"

class Ball
{
private:
	Vector2 position;
	Vector2 velocity;
	int radius;
	Color color;
	Paddle* paddle;
	GameManager* gameManager;
	bool onPaddle = true;
	void WallCollision();
	void PaddleCollision();
	void Movement(float dt);
public:
	Ball(Vector2 position, Vector2 velocity, int radius, Color color, GameManager* gameManager);
	Ball();
	~Ball();
	void Init(Paddle* paddle);
	void Update(float dt);
	void Draw();

	void BrickCollision(Brick* brick);
	void SetOnPaddle();
};

#endif
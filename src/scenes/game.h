#ifndef GAME_H
#define GAME_H

#include "../scene.h"
#include <vector>
#include "../constant.h"
#include "../ball.h"
#include "../paddle.h"
#include "../brick.h"
#include "../sceneManager.h"

class Game : public Scene
{
private:
	Ball ball = Ball(Vector2{ 500, 500 }, Vector2{ 0, -500 }, 5, WHITE);
	Paddle paddle = Paddle(Vector2{ WINDOW_SIZE.x / 2 + 100, WINDOW_SIZE.y - 50 }, Vector2{ 100,25 }, WHITE);

	std::vector<Brick> bricks;
	int bricksLine = 3;

	void InitBricks();
	void Reset();
public:
	Game();
	~Game();
	void Update(float dt) override;
	void Draw() override;
};
extern Game* game;

#endif
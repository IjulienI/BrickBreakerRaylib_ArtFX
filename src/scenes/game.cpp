#include "game.h"

Game* game = nullptr;

void Game::InitBricks()
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < bricksLine; j++) {
			Brick brick = { Vector2{(float)BRICKS_WITDH * i + 2 ,(float)BRICKS_HEIGHT * j + 2},Vector2{BRICKS_WITDH - 2,BRICKS_HEIGHT - 2} };
			bricks.push_back(brick);
		}
	}
}

void Game::Reset()
{
	if (bricksLine >= 14) {
		sceneManager->SetScene(ENDGAME);
	}
	ball.SetOnPaddle();
	bricks.clear();
	bricksLine += 3;
	InitBricks();
}

Game::Game()
{
	ball.Init(&paddle);
	InitBricks();
}

Game::~Game()
{
	ball.~Ball();
}

void Game::Update(float dt)
{
	ball.Update(dt);
	int destroyedCount = 0;
	for (int i = 0; i < bricks.size(); i++) {
		ball.BrickCollision(&bricks[i]);
		if (bricks[i].GetDestoyed()) destroyedCount++;
		if (destroyedCount == bricks.size()) Reset();
	}
	paddle.Update(dt);
}

void Game::Draw()
{
	ball.Draw();
	paddle.Draw();
	for (int i = 0; i < bricks.size(); i++) {
		bricks[i].Draw();
	}
}

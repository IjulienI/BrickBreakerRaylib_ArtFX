#include "game.h"
#include "../sceneManager.h"

Game* game = nullptr;

void Game::InitBricks()
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < bricksLine; j++) {
			Brick brick = { Vector2{(float)BRICKS_WITDH * i + 2 ,(float)BRICKS_HEIGHT * j + 2},Vector2{BRICKS_WITDH - 2,BRICKS_HEIGHT - 2},gameManager };
			bricks.push_back(brick);
		}
	}
}

void Game::Reset()
{
	if (bricksLine >= 14) {
		sceneManager->SetScene(MENU);
	}
	ball.SetOnPaddle();
	bricks.clear();
	bricksLine += 3;
	InitBricks();
}

void Game::DrawScore()
{
	DrawText(TextFormat("SCORE : %i", gameManager->GetScore()), 5, (WINDOW_SIZE.y /2) - 16, 16, WHITE);
	DrawText(TextFormat("LIFE : %i", gameManager->GetLife()), 5, (WINDOW_SIZE.y / 2), 16, WHITE);
}

void Game::ResetLevel()
{
	gameManager->ResetLife();
	gameManager->ResetScore();
	ball.SetOnPaddle();
	bricks.clear();
	InitBricks();
}

Game::Game()
{
	gameManager = new GameManager(this);
	ball = Ball(Vector2{ 500, 500 }, Vector2{ 0, -500 }, 5, WHITE, gameManager);
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
	if (gameManager->GetLife() == 0) {
		ResetLevel();
		//Sorry, manque de temps ;(
	}
}

void Game::Draw()
{
	ball.Draw();
	paddle.Draw();
	for (int i = 0; i < bricks.size(); i++) {
		bricks[i].Draw();
	}
	DrawScore();
}

#include "gameManager.h"

GameManager* gameManager = nullptr;

GameManager::GameManager()
{
}

GameManager::GameManager(Scene* scene)
{
	this->scene = scene;
}

GameManager::~GameManager()
{
}

void GameManager::RemoveLife()
{
	life--;
}

int GameManager::GetScore()
{
	return score;
}

void GameManager::ResetScore()
{
	score = 0;
}

void GameManager::SetScore(int newScore)
{
	score = newScore;
}

void GameManager::AddScore(int amount)
{
	score += amount;
}

int GameManager::GetLife()
{
	return life;
}

void GameManager::ResetLife()
{
	life = baseLife;
}

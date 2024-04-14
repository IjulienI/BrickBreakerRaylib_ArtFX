#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "scene.h"

class GameManager {
private:
	const int baseLife = 5;
	int score = 0;
	int hightScore = 0;
	int life = baseLife;
	int time = 0;
	int bestTime = 0;
	Scene* scene;
public:
	GameManager();
	GameManager(Scene* scene);
	~GameManager();
	void RemoveLife();
	int GetScore();
	void ResetScore();
	void SetScore(int newScore);
	void AddScore(int amount);

	int GetLife();
	void ResetLife();
};
extern GameManager* gameManager;

#endif 
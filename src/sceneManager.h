#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include "scene.h"
#include "./scenes/menu.h"
#include "./scenes/game.h"

enum Scenes {
	MENU,
	GAME,
	ENDGAME
};

class SceneManager
{
private:
	Scene* currentScene;

public:
	SceneManager();
	~SceneManager();
	void SetScene(enum Scenes newScene);
	void Update(float dt);
	void Draw();
};
extern SceneManager* sceneManager;

#endif
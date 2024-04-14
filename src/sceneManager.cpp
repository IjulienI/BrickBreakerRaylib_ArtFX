#include "sceneManager.h"

SceneManager* sceneManager = nullptr;

SceneManager::SceneManager()
{
	SetScene(MENU);
}

SceneManager::~SceneManager()
{
	currentScene->~Scene();
}

void SceneManager::SetScene(enum Scenes newScene)
{
	delete currentScene;
	switch (newScene) {
	case MENU:
		menu = new Menu(this);
		currentScene = menu;
		break;
	case GAME:
		game = new Game();
		currentScene = game;
		break;
	case ENDGAME:
		break;
	}
}

void SceneManager::Update(float dt)
{
	currentScene->Update(dt);
}

void SceneManager::Draw()
{
	currentScene->Draw();
}

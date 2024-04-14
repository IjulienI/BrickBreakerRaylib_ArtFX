#include "menu.h"
#include "../sceneManager.h"

Menu* menu = nullptr;

Menu::Menu(SceneManager* sceneManager)
{
	this->manager = sceneManager;
}

Menu::~Menu()
{
}

void Menu::Update(float dt)
{
	Rectangle play = Rectangle{(WINDOW_SIZE.x / 2) - 50 ,300,100,50};
	if (GuiButton(play,"PLAY")) {
		manager->SetScene(GAME);
	}
	Rectangle exit = Rectangle{ (WINDOW_SIZE.x / 2) - 50 ,400,100,50 };
	if (GuiButton(exit, "EXIT")) {
		CloseWindow();
	}
}

void Menu::Draw()
{
	
}

#include "menu.h"

Menu* menu = nullptr;

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Update(float dt)
{
}

void Menu::Draw()
{
	DrawText("Hello", 500, 500, 15, WHITE);
}

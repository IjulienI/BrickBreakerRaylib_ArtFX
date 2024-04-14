#ifndef MENU_H
#define MENU_H

#include "../src/scene.h"
#include <raygui.h>


class Menu : public Scene
{
private:
	SceneManager* manager;
public:
	Menu(SceneManager* sceneManager);
	~Menu();
	void Update(float dt) override;
	void Draw() override;
};
extern Menu* menu;

#endif
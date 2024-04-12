#ifndef MENU_H
#define MENU_H

#include "../src/scene.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();
	void Update(float dt) override;
	void Draw() override;
};
extern Menu* menu;

#endif
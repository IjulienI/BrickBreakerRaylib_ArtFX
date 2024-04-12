#ifndef DEBUG_H
#define DEBUG_H

#include <raylib.h>

class Debug
{
private:
	float deltaTime;
public:
	Debug();
	~Debug();
	void Draw();
	void Update(float dt);
};
extern Debug* debugOui;

#endif
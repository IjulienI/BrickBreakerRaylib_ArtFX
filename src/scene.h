#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>

class Scene
{
public:
	Scene();
	~Scene();
	virtual void Update(float dt);
	virtual void Draw();
};

#endif
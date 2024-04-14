#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>
class SceneManager;

class Scene
{
private:
	SceneManager* manager;
public:
	Scene();
	~Scene();
	virtual void Update(float dt);
	virtual void Draw();
};

#endif
#ifndef APPLICATION_H
#define APPLICATION_H

#include <raylib.h>
#include "constant.h"
#include "sceneManager.h"
#include "debug.h"

class Application {
public:
	Application();
	~Application();

	void Initialize();
	void Loop();
private:
	void Draw();
	void Clear();

	bool debug = true;
};
extern Application* application;

#endif
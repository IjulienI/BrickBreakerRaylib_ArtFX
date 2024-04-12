#include "application.h"

Application* application = nullptr;

Application::Application()
{
	sceneManager = new SceneManager;
	debugOui = new Debug;
}

Application::~Application()
{
}

void Application::Initialize()
{
	InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, WINDOW_NAME);
	SetWindowState(FLAG_VSYNC_HINT);
	while (!WindowShouldClose()) {
		Loop();
		Draw();
	}
	Clear();
}

void Application::Loop()
{
	float deltaTime = GetFrameTime();
	sceneManager->Update(deltaTime);
	if (debug) {
		debugOui->Update(deltaTime);
	}
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	sceneManager->Draw();
	if (debug) {
		debugOui->Draw();
	}

	EndDrawing();
}

void Application::Clear()
{
	sceneManager->~SceneManager();
}

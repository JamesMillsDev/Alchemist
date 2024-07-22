#pragma once

#include <Alchemist/Alchemist.h>

#include <Alchemist/GameFramework/GameInstance.h>

class Screen;
class RenderEngine;

namespace Alchemist
{
	DLL Screen* GetScreen();
	DLL RenderEngine* GetRenderEngine();
}

class DLL Application
{
public:
	Application(const Application&) = delete;
	Application(Application&&) = delete;

public:
	template<derived<GameInstance> GAME>
	static void Run(const char* title, int width, int height);

	friend Screen* Alchemist::GetScreen();
	friend RenderEngine* Alchemist::GetRenderEngine();

public:
	Application& operator=(const Application&) = delete;
	Application& operator=(Application&&) = delete;

private:
	static Application* m_app;

private:
	GameInstance* m_game;

	Screen* m_screen;
	RenderEngine* m_renderer;

private:
	Application(const char* title, int width, int height, GameInstance* game);
	~Application();

private:
	void Process();

	void Tick();
	void Render();

};

template <derived<GameInstance> GAME>
void Application::Run(const char* title, int width, int height)
{
	GAME* game = new GAME;

	Application* app = new Application(title, width, height, game);

	app->Process();

	delete app;
}

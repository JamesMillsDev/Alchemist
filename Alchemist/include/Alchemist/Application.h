#pragma once

#include <Alchemist/Alchemist.h>

class Screen;
class RenderEngine;

namespace Alchemist
{
	Screen* GetScreen();
	RenderEngine* GetRenderEngine();
}

class DLL Application
{
public:
	Application(const char* title, int width, int height);
	~Application();

	Application(const Application&) = delete;
	Application(Application&&) = delete;

public:
	void Run();

	friend Screen* Alchemist::GetScreen();
	friend RenderEngine* Alchemist::GetRenderEngine();

public:
	Application& operator=(const Application&) = delete;
	Application& operator=(Application&&) = delete;

private:
	static Application* m_app;

private:
	Screen* m_screen;
	RenderEngine* m_renderer;

private:
	void Tick();
	void Render();

};
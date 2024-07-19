#pragma once

#include <Alchemist/Alchemist.h>

class Screen;
class RenderEngine;

class DLL Application
{
public:
	Application(const char* title, int width, int height);
	~Application();

	Application(const Application&) = delete;
	Application(Application&&) = delete;

public:
	void Run();

public:
	Application& operator=(const Application&) = delete;
	Application& operator=(Application&&) = delete;

private:
	void Tick();
	void Render();

private:
	Screen* m_screen;
	RenderEngine* m_renderer;

};
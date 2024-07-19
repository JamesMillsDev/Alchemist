#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Renderer;

class Screen;

class DLL RenderEngine
{
	friend class Application;

public:
	RenderEngine(const RenderEngine&) = delete;
	RenderEngine(RenderEngine&&) = delete;

public:
	RenderEngine& operator=(const RenderEngine&) = delete;
	RenderEngine& operator=(RenderEngine&&) = delete;

private:
	SDL_Renderer* m_renderer;

private:
	RenderEngine();
	~RenderEngine();

private:
	int Initialise(const Screen* screen, int index, uint flags);

	void BeginFrame() const;
	void EndFrame() const;

};
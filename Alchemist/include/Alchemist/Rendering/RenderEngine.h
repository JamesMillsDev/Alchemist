#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Rect;
struct SDL_Renderer;

class Screen;
class Texture;

class DLL RenderEngine
{
	friend class Application;
	friend class Texture;

public:
	RenderEngine(const RenderEngine&) = delete;
	RenderEngine(RenderEngine&&) = delete;

public:
	void RenderTexture(const Texture* texture, const SDL_Rect* dst = nullptr, const SDL_Rect* src = nullptr) const;

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
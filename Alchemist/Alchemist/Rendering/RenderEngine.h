#pragma once

#include <Alchemist/Alchemist.h>
#include <SDL/SDL_image.h>

#include <list>

struct SDL_Renderer;

class Screen;

using std::list;

class DLL RenderEngine
{
	friend class Application;

public:
	RenderEngine(const RenderEngine&) = delete;
	RenderEngine(RenderEngine&&) = delete;

public:
	SDL_Texture* Load(const char* file, IMG_InitFlags type);
	void Unload(SDL_Texture* texture);

	void RenderTexture(SDL_Texture* texture, const SDL_Rect* dst = nullptr, const SDL_Rect* src = nullptr) const;

public:
	RenderEngine& operator=(const RenderEngine&) = delete;
	RenderEngine& operator=(RenderEngine&&) = delete;

private:
	SDL_Renderer* m_renderer;

	list<SDL_Texture*> m_loadedTextures;

private:
	RenderEngine();
	~RenderEngine();

private:
	int Initialise(const Screen* screen, int index, uint flags);

	void BeginFrame() const;
	void EndFrame() const;

};
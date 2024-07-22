#pragma once

#include <Alchemist/Alchemist.h>
#include <SDL/SDL_image.h>

#include <list>

#include "Texture.h"

struct SDL_Texture;

class Screen;

using std::list;

class DLL RenderEngine
{
	friend class Application;

public:
	RenderEngine(const RenderEngine&) = delete;
	RenderEngine(RenderEngine&&) = delete;

public:
	SDL_Texture* Load(const char* file, ETextureFormat type, Texture* texture);
	void Unload(Texture* texture);

	void RenderTexture(const Texture* texture, const SDL_Rect* dst = nullptr, const SDL_Rect* src = nullptr) const;

public:
	RenderEngine& operator=(const RenderEngine&) = delete;
	RenderEngine& operator=(RenderEngine&&) = delete;

private:
	SDL_Renderer* m_renderer;

	list<Texture*> m_loadedTextures;

private:
	RenderEngine();
	~RenderEngine();

private:
	int Initialise(const Screen* screen, int index, uint flags);

	void BeginFrame() const;
	void EndFrame() const;

};
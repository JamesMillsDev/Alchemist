#include "Alchemist/Rendering/RenderEngine.h"

#include <iostream>
#include <sstream>
#include <Alchemist/Screen.h>
#include <Alchemist/Rendering/Texture.h>
#include <SDL/SDL_render.h>

using std::stringstream;

SDL_Texture* RenderEngine::Load(const char* file, ETextureFormat type, Texture* texture)
{
	stringstream path;
	path << "Content\\Textures\\";
	path << file;

	switch (type)  // NOLINT(clang-diagnostic-switch-enum)
	{
	case Jpg:
		path << ".jpg";
		break;

	case Png:
		path << ".png";
		break;

	case Tiff:
		path << ".tif";
		break;

	default:
		path << ".png";
		break;
	}

	SDL_Surface* surface = IMG_Load(path.str().c_str());
	if(surface == nullptr)
	{
		std::cout << "Error loading image: " << IMG_GetError() << "\n";
		return nullptr;
	}

	SDL_Texture* txt = SDL_CreateTextureFromSurface(m_renderer, surface);
	if(txt == nullptr)
	{
		std::cout << "Error creating texture\n";
		return nullptr;
	}

	SDL_FreeSurface(surface);

	m_loadedTextures.emplace_back(texture);

	return txt;
}

void RenderEngine::Unload(Texture* texture)
{
	if (std::ranges::find(m_loadedTextures, texture) == m_loadedTextures.end())
		return;

	SDL_DestroyTexture(*texture);
	m_loadedTextures.remove(texture);
}

void RenderEngine::RenderTexture(const Texture* texture, const SDL_Rect* dst, const SDL_Rect* src) const
{
	SDL_RenderCopy(m_renderer, *texture, src, dst);
}

RenderEngine::RenderEngine()
	: m_renderer{ nullptr }
{
}

RenderEngine::~RenderEngine()
{
	for (const auto& texture : m_loadedTextures)
		SDL_DestroyTexture(*texture);
		
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;

	IMG_Quit();
}

int RenderEngine::Initialise(const Screen* screen, const int index, const uint flags)
{
	if(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF) == 0)
	{
		std::cout << "Failed to initialise image library: " << IMG_GetError() << "\n";
		return EXIT_FAILURE;
	}

	m_renderer = SDL_CreateRenderer(screen->m_window, index, flags);
	if(m_renderer == nullptr)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

	return EXIT_SUCCESS;
}

void RenderEngine::BeginFrame() const
{
	SDL_RenderClear(m_renderer);
}

void RenderEngine::EndFrame() const
{
	SDL_RenderPresent(m_renderer);
}

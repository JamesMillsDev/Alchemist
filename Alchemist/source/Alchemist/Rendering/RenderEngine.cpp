#include "Alchemist/Rendering/RenderEngine.h"

#include <iostream>
#include <Alchemist/Screen.h>
#include <Alchemist/Rendering/Texture.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_render.h>

void RenderEngine::RenderTexture(const Texture* texture, const SDL_Rect* dst, const SDL_Rect* src) const
{
	SDL_RenderCopy(m_renderer, *texture, src, dst);
}

RenderEngine::RenderEngine() = default;

RenderEngine::~RenderEngine()
{
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

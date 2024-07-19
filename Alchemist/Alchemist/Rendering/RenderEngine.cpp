#include "RenderEngine.h"

#include <iostream>
#include <SDL/SDL_render.h>
#include <SDL/SDL_image.h>

#include "Alchemist/Screen.h"

RenderEngine::RenderEngine()
	: m_renderer{ nullptr }
{
}

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

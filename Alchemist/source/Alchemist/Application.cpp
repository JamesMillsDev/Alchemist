#include "Alchemist/Application.h"

#include <Alchemist/Screen.h>
#include <Alchemist/Rendering/RenderEngine.h>
#include <SDL/SDL_events.h>
#include <SDL/SDL_render.h>

Application* Application::m_app;

namespace Alchemist
{
	Screen* GetScreen()
	{
		return Application::m_app->m_screen;
	}

	RenderEngine* GetRenderEngine()
	{
		return Application::m_app->m_renderer;
	}
}

void Application::Process()
{
	if (m_app)
		return;

	m_app = this;

	if (m_screen->Open() == EXIT_FAILURE)
		return;

	if (m_renderer->Initialise(m_screen, -1, SDL_RENDERER_ACCELERATED) == EXIT_FAILURE)
		return;

	m_game->BeginPlay();

	while (true)
	{
		SDL_Event e;
		if (SDL_WaitEvent(&e))
		{
			Tick();

			if (e.type == SDL_QUIT)
				break;
		}

		m_renderer->BeginFrame();

		Render();

		m_renderer->EndFrame();
	}

	m_game->EndPlay();
}

Application::Application(const char* title, const int width, const int height, GameInstance* game)
	: m_game{ game }, m_screen{ new Screen(title, width, height) }, m_renderer{ new RenderEngine }
{
}

Application::~Application()
{
	delete m_game;
	m_game = nullptr;

	delete m_screen;
	m_renderer = nullptr;

	delete m_renderer;
	m_renderer = nullptr;
}

void Application::Tick()
{
	m_game->Tick();
}

void Application::Render()
{
	m_game->Render();
}

#include "Application.h"

#include <SDL/SDL_events.h>
#include <SDL/SDL_render.h>

#include "Screen.h"
#include "Rendering/RenderEngine.h"

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

Application::Application(const char* title, const int width, const int height)
	: m_screen{ new Screen(title, width, height) }, m_renderer{ new RenderEngine }
{
}

Application::~Application()
{
	delete m_screen;
	m_renderer = nullptr;

	delete m_renderer;
	m_renderer = nullptr;
}

void Application::Run()
{
	if (m_app)
		return;

	m_app = this;

	if (m_screen->Open() == EXIT_FAILURE)
		return;

	if (m_renderer->Initialise(m_screen, -1, SDL_RENDERER_ACCELERATED) == EXIT_FAILURE)
		return;

	while(true)
	{
		SDL_Event e;
		if(SDL_WaitEvent(&e))
		{
			Tick();

			if (e.type == SDL_QUIT)
				break;
		}

		m_renderer->BeginFrame();

		Render();

		m_renderer->EndFrame();
	}
}

void Application::Tick()
{
}

void Application::Render()
{
}

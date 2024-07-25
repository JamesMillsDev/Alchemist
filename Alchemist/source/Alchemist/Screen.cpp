#include "Alchemist/Screen.h"

#include <format>
#include <Alchemist/Utilities/Console.h>
#include <SDL/SDL.h>

int Screen::Width() const
{
	return m_width;
}

int Screen::Height() const
{
	return m_height;
}

const char* Screen::Title() const
{
	return m_title;
}

Screen::Screen(const char* title, int width, int height)
	: m_window{ nullptr }, m_title{ new char[strlen(title)] }, m_width{ width },
	m_height{ height }
{
	strcpy_s(m_title, strlen(title) + 1, title);
}

Screen::~Screen()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	m_title = nullptr;

	SDL_Quit();
}

int Screen::Open()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		Console::LogError(std::format("SDL failed to initialize: {}", SDL_GetError()));
		return EXIT_FAILURE;
	}

	Console::Log("Successfully initialised SDL!");

	m_window = SDL_CreateWindow(m_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);
	if(m_window == nullptr)
	{
		Console::LogError(std::format("SDL failed to create window: {}", SDL_GetError()));
		return EXIT_FAILURE;
	}

	Console::Log("Successfully created window!");

	return EXIT_SUCCESS;
}

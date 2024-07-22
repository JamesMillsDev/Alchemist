#pragma once

#include <Alchemist/Alchemist.h>

struct SDL_Window;

class DLL Screen
{
	friend class Application;
	friend class RenderEngine;

public:
	Screen(const Screen&) = delete;
	Screen(Screen&&) = delete;

public:
	[[nodiscard]] int Width() const;
	[[nodiscard]] int Height() const;
	[[nodiscard]] const char* Title() const;

public:
	Screen& operator=(const Screen&) = delete;
	Screen& operator=(Screen&&) = delete;

private:
	SDL_Window* m_window;

	char* m_title;
	int m_width;
	int m_height;

private:
	Screen(const char* title, int width, int height);
	~Screen();

private:
	int Open();

};
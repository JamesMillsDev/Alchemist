#pragma once

#include <Alchemist/Alchemist.h>

#include <Alchemist/Rendering/Color.h>
#include <SDL/SDL_render.h>

struct SDL_Renderer;

struct Rect;
struct Vector2;

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
	void DrawTexture(const Texture* texture, int x, int y) const;
	void DrawTexture(const Texture* texture, int x, int y, int w, int h) const;
	void DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle) const;
	void DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle, Vector2 pivot) const;
	void DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle, Vector2 pivot, SDL_RendererFlip flip) const;

	void DrawTexture(const Texture* texture, Vector2 pos) const;
	void DrawTexture(const Texture* texture, Vector2 pos, Vector2 size) const;
	void DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle) const;
	void DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle, Vector2 pivot) const;
	void DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle, Vector2 pivot, SDL_RendererFlip flip) const;

	void DrawTexture(const Texture* texture, Rect rect) const;
	void DrawTexture(const Texture* texture, Rect rect, float angle) const;
	void DrawTexture(const Texture* texture, Rect rect, float angle, Vector2 pivot) const;
	void DrawTexture(const Texture* texture, Rect rect, float angle, Vector2 pivot, SDL_RendererFlip flip) const;

	void DrawTexture(const Texture* texture, Rect src, Rect dst) const;
	void DrawTexture(const Texture* texture, Rect src, Rect dst, float angle) const;
	void DrawTexture(const Texture* texture, Rect src, Rect dst, float angle, Vector2 pivot) const;
	void DrawTexture(const Texture* texture, Rect src, Rect dst, float angle, Vector2 pivot, SDL_RendererFlip flip) const;

	void DrawCircle(int x, int y, int radius, Color color) const;
	void DrawCircleLines(int x, int y, int radius, Color color) const;

	void DrawRect(int x, int y, int w, int h, Color color) const;
	void DrawRectLines(int x, int y, int w, int h, Color color) const;
	void DrawRect(Vector2 pos, Vector2 size, Color color) const;
	void DrawRectLines(Vector2 pos, Vector2 size, Color color) const;
	void DrawRect(Rect rect, Color color) const;

	void SetBackgroundColor(Color color);

public:
	RenderEngine& operator=(const RenderEngine&) = delete;
	RenderEngine& operator=(RenderEngine&&) = delete;

private:
	SDL_Renderer* m_renderer;

	Color m_backgroundColor;

private:
	RenderEngine();
	~RenderEngine();

private:
	int Initialise(const Screen* screen, int index, uint flags, Color background);

	void BeginFrame() const;
	void EndFrame() const;

};
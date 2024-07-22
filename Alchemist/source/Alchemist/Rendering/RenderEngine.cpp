#include "Alchemist/Rendering/RenderEngine.h"

#include <iostream>
#include <Alchemist/Screen.h>
#include <Alchemist/Rendering/Color.h>
#include <Alchemist/Rendering/Texture.h>
#include <Alchemist/Utilities/Rect.h>
#include <Alchemist/Utilities/Vector2.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_render.h>

void RenderEngine::DrawTexture(const Texture* texture, int x, int y, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	SDL_Point size;
	SDL_QueryTexture(*texture, nullptr, nullptr, &size.x, &size.y);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { x, y, size.x, size.y };

	SDL_RenderCopy(m_renderer, *texture, &source, &destination);
}

void RenderEngine::DrawTexture(const Texture* texture, int x, int y, int w, int h, Color color) const
{
	DrawTexture(texture, x, y, color);
}

void RenderEngine::DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	SDL_Point size;
	SDL_QueryTexture(*texture, nullptr, nullptr, &size.x, &size.y);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { x, y, w, h };

	SDL_RenderCopyEx(m_renderer, *texture, &source, &destination, angle, nullptr, SDL_FLIP_NONE);
}

void RenderEngine::DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle, Vector2 pivot, Color color) const
{
	DrawTexture(texture, x, y, w, h, angle, pivot, SDL_FLIP_NONE, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Vector2 pos, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	SDL_Point size;
	SDL_QueryTexture(*texture, nullptr, nullptr, &size.x, &size.y);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { pos.x, pos.y, size.x, size.y };

	SDL_RenderCopy(m_renderer, *texture, &source, &destination);
}

void RenderEngine::DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { pos.x, pos.y, size.x, size.y };

	SDL_RenderCopy(m_renderer, *texture, &source, &destination);
}

void RenderEngine::DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { pos.x, pos.y, size.x, size.y };

	SDL_RenderCopyEx(m_renderer, *texture, &source, &destination, angle, nullptr, SDL_FLIP_NONE);
}

void RenderEngine::DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle, Vector2 pivot, Color color) const
{
	DrawTexture(texture, pos, size, angle, pivot, SDL_FLIP_NONE, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect rect, Color color) const
{
	DrawTexture(texture, rect.x, rect.y, rect.width, rect.height, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect rect, float angle, Color color) const
{
	DrawTexture(texture, rect.x, rect.y, rect.width, rect.height, angle, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect rect, float angle, Vector2 pivot, Color color) const
{
	DrawTexture(texture, rect.x, rect.y, rect.width, rect.height, angle, pivot, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect rect, float angle, Vector2 pivot,
	SDL_RendererFlip flip, Color color) const
{
	DrawTexture(texture, rect.x, rect.y, rect.width, rect.height, angle, pivot, flip, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect src, Rect dst, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	const SDL_Rect source = { src.x, src.y, src.width, src.height };
	const SDL_Rect destination = { dst.x, dst.y, dst.width, dst.height };

	SDL_RenderCopy(m_renderer, *texture, &source, &destination);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect src, Rect dst, float angle, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	const SDL_Rect source = { src.x, src.y, src.width, src.height };
	const SDL_Rect destination = { dst.x, dst.y, dst.width, dst.height };

	SDL_RenderCopyEx(m_renderer, *texture, &source, &destination, angle, nullptr, SDL_FLIP_NONE);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect src, Rect dst, float angle, Vector2 pivot, Color color) const
{
	DrawTexture(texture, src, dst, angle, pivot, SDL_FLIP_NONE, color);
}

void RenderEngine::DrawTexture(const Texture* texture, Rect src, Rect dst, float angle, Vector2 pivot,
	SDL_RendererFlip flip, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	const SDL_Rect source = { src.x, src.y, src.width, src.height };
	const SDL_Rect destination = { dst.x, dst.y, dst.width, dst.height };

	const SDL_Point center = { pivot.x, pivot.y };
	SDL_RenderCopyEx(m_renderer, *texture, &source, &destination, angle, &center, flip);
}

void RenderEngine::DrawTexture(const Texture* texture, Vector2 pos, Vector2 size, float angle, Vector2 pivot,
	SDL_RendererFlip flip, Color color) const
{
	DrawTexture(texture, pos.x, pos.y, size.x, size.y, angle, pivot, flip, color);
}

void RenderEngine::DrawTexture(const Texture* texture, int x, int y, int w, int h, float angle, Vector2 pivot,
	SDL_RendererFlip flip, Color color) const
{
	texture->ResetTint();
	texture->Tint(color);

	SDL_Point size;
	SDL_QueryTexture(*texture, nullptr, nullptr, &size.x, &size.y);

	const SDL_Rect source = { 0, 0, size.x, size.y };
	const SDL_Rect destination = { x, y, w, h };

	const SDL_Point center = { pivot.x, pivot.y };
	SDL_RenderCopyEx(m_renderer, *texture, &source, &destination, angle, &center, flip);
}

void RenderEngine::DrawCircle(int x, int y, int radius, Color color) const
{
	int offsetX = 0;
	int offsetY = radius;
	int d = radius - 1;

	int status = 0;

	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	while (offsetY >= offsetX)
	{
		status += SDL_RenderDrawLine(m_renderer, x - offsetY, y + offsetX, x + offsetY, y + offsetX);
		status += SDL_RenderDrawLine(m_renderer, x - offsetX, y + offsetY, x + offsetX, y + offsetY);
		status += SDL_RenderDrawLine(m_renderer, x - offsetX, y - offsetY, x + offsetX, y - offsetY);
		status += SDL_RenderDrawLine(m_renderer, x - offsetY, y - offsetX, x + offsetY, y - offsetX);

		if (status < 0)
			break;

		if (d >= 2 * offsetX)
		{
			d -= 2 * offsetX + 1;
			offsetX++;
		}
		else if (d < 2 * (radius - offsetY))
		{
			d += 2 * offsetY - 1;
			offsetY -= 1;
		}
		else
		{
			d += 2 * (offsetY - offsetX - 1);
			offsetY -= 1;
			offsetX += 1;
		}
	}
}

void RenderEngine::DrawCircleLines(int x, int y, int radius, Color color) const
{
	int offsetX = 0;
	int offsetY = radius;
	int d = radius - 1;

	int status = 0;

	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	while (offsetY >= offsetX)
	{
		status += SDL_RenderDrawPoint(m_renderer, x + offsetX, y + offsetY);
		status += SDL_RenderDrawPoint(m_renderer, x + offsetY, y + offsetX);
		status += SDL_RenderDrawPoint(m_renderer, x - offsetX, y + offsetY);
		status += SDL_RenderDrawPoint(m_renderer, x - offsetY, y + offsetX);
		status += SDL_RenderDrawPoint(m_renderer, x + offsetX, y - offsetY);
		status += SDL_RenderDrawPoint(m_renderer, x + offsetY, y - offsetX);
		status += SDL_RenderDrawPoint(m_renderer, x - offsetX, y - offsetY);
		status += SDL_RenderDrawPoint(m_renderer, x - offsetY, y - offsetX);

		if (status < 0)
			break;

		if (d >= 2 * offsetX)
		{
			d -= 2 * offsetX + 1;
			offsetX++;
		}
		else if (d < 2 * (radius - offsetY))
		{
			d += 2 * offsetY - 1;
			offsetY -= 1;
		}
		else
		{
			d += 2 * (offsetY - offsetX - 1);
			offsetY -= 1;
			offsetX += 1;
		}
	}
}

void RenderEngine::DrawRect(int x, int y, int w, int h, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { x, y, w, h };
	SDL_RenderFillRect(m_renderer, &sdlRect);
}

void RenderEngine::DrawRectLines(int x, int y, int w, int h, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { x, y, w, h };
	SDL_RenderDrawRect(m_renderer, &sdlRect);
}

void RenderEngine::DrawRect(Vector2 pos, Vector2 size, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { pos.x, pos.y, size.x, size.y };
	SDL_RenderFillRect(m_renderer, &sdlRect);
}

void RenderEngine::DrawRectLines(Vector2 pos, Vector2 size, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { pos.x, pos.y, size.x, size.y };
	SDL_RenderDrawRect(m_renderer, &sdlRect);
}

void RenderEngine::DrawRect(Rect rect, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { rect.x, rect.y, rect.width, rect.height };
	SDL_RenderFillRect(m_renderer, &sdlRect);
}

void RenderEngine::DrawRectLines(Rect rect, Color color) const
{
	SDL_SetRenderDrawColor(m_renderer, color.red, color.green, color.blue, color.alpha);

	const SDL_Rect sdlRect = { rect.x, rect.y, rect.width, rect.height };
	SDL_RenderDrawRect(m_renderer, &sdlRect);
}

void RenderEngine::SetBackgroundColor(Color color)
{
	m_backgroundColor = color;
}

RenderEngine::RenderEngine() = default;

RenderEngine::~RenderEngine()
{
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;

	IMG_Quit();
}

int RenderEngine::Initialise(const Screen* screen, const int index, const uint flags, Color background)
{
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF) == 0)
	{
		std::cout << "Failed to initialise image library: " << IMG_GetError() << "\n";
		return EXIT_FAILURE;
	}

	m_renderer = SDL_CreateRenderer(screen->m_window, index, flags);
	if (m_renderer == nullptr)
	{
		std::cout << "Failed to create renderer: " << SDL_GetError() << "\n";
		return EXIT_FAILURE;
	}

	m_backgroundColor = background;

	return EXIT_SUCCESS;
}

void RenderEngine::BeginFrame() const
{
	SDL_SetRenderDrawColor(m_renderer, m_backgroundColor.red, m_backgroundColor.green, m_backgroundColor.blue, m_backgroundColor.alpha);
	SDL_RenderClear(m_renderer);
}

void RenderEngine::EndFrame() const
{
	SDL_RenderPresent(m_renderer);
}

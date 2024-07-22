#include "Alchemist/Utilities/Rect.h"

#include <Alchemist/Utilities/Vector2.h>

Rect::Rect()
	: x{ 0 }, y{ 0 }, width{ 0 }, height{ 0 }
{
}

Rect::Rect(const Vector2 pos, const Vector2 size)
	: x{ pos.x }, y{ pos.y }, width{ size.x }, height{ size.y }
{
}

Rect::Rect(const int x, const int y, const int w, const int h)
	: x{ x }, y{ y }, width{ w }, height{ h }
{
}
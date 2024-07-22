#pragma once

struct SDL_Rect;
struct Vector2;

struct Rect
{
public:
	int x;
	int y;
	int width;
	int height;

public:
	Rect();
	Rect(Vector2 pos, Vector2 size);
	Rect(int x, int y, int w, int h);

};
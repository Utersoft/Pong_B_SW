#pragma once
#include "screen.h"

class Brick {
public:
	Brick(int life, int w, int h, int x, int y, int r, int g, int b, int a);
	Brick();
	

	inline bool isDestroyed() const { return destroyed; }

	void SetX(int x);
	void SetY(int y);
	void SetLife(int life);
	int GetX() { return x; };
	int GetY() { return y; };
	int GetW() { return w; };
	int GetH() { return h; };
	void draw(SDL_Renderer *renderer) const;

	Brick operator=(const Brick &brick);

private:
	int life;
	bool destroyed = false;

	int w, h;
	int x, y;
	int r, g, b, a;
	
	bool haveBonus = false;
protected:
};
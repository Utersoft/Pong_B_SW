#pragma once
#include "screen.h"

class Brick : public Screen {
public:
	Brick(const Screen& screen, int life, int w, int h, int x, int y, int r, int g, int b, int a);
	//Brick();
	

	inline bool isDestroyed() const { return destroyed; }

	void draw() const;

private:
	int life;
	bool destroyed = false;

	int w, h;
	int x, y;
	int r, g, b, a;
	
	bool haveBonus = false;
};
#pragma once
#include "Screen.h"

class Rect : public Screen {
public:
	//Constructeur
	Rect(const Screen &window, int w, int h, int x, int y, int r, int g, int b, int o, int type);

	void draw() const;
	void pollEvents1(SDL_Event& event);
	void pollEvents2(SDL_Event& event);
	
	
	int type;

private:
	int w, h;
	int x, y;
	int r, g, b, o;
	
};
#pragma once
#include "Screen.h"

class Rect : public Screen {
public:
	//Constructeur
	Rect(const Screen &window, int w, int h, int x, int y, int r, int g, int b, int o);

	void draw() const;
	void pollEvents(SDL_Event& event, Control &playerInput);
	

	
	//Assesseurs
	int GetX();
	int GetY();

	//Mutateurs
	void SetX(int x);
	void SetY(int y);

private:
	int w, h;
	int x, y;
	int r, g, b, o;
};
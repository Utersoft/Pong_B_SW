#include "Brick.h"

/*Brick::Brick()
{
	life = 0;
	w = 0;
	h = 0;
	x = 0;
	y = 0;
	r = 0;
	g = 0;
	b = 0;
	a = 0;
}*/

Brick::Brick(const Screen& screen, int life, int w, int h, int x, int y, int r, int g, int b, int a) :
	Screen (screen)
{
	this->life = life;
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

void Brick::draw() const
{
	SDL_Rect brick;

	brick.w = w;
	brick.h = h;
	brick.x = x;
	brick.y = y;

	switch (life) {
	case 1:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
		break;
	case 2:
		SDL_SetRenderDrawColor(renderer, 0, 200, 0, 1);
		break;
	case 3:
		SDL_SetRenderDrawColor(renderer, 0, 0, 200, 1);
		break;
	}
	SDL_RenderFillRect(renderer, &brick);
}



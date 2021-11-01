#include "Brick.h"

Brick::Brick()
{
	life = 1;
	w = BRICK_WIDTH;
	h = BRICK_HEIGHT;
	x = BRICK_ORIGIN_X;
	y = BRICK_ORIGIN_Y;
	r = 255;
	g = 255;
	b = 255;
	a = 1;
}

Brick::Brick(int life, int w, int h, int x, int y, int r, int g, int b, int a)
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

void Brick::draw(SDL_Renderer *renderer) const
{
	SDL_Rect brick;

	brick.w = this->w;
	brick.h = this->h;
	brick.x = this->x;
	brick.y = this->y;

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



Brick Brick::operator=(const Brick& brick)
{
	this->x = brick.x;
	this->y = brick.y;
	this->w = brick.w;
	this->h = brick.h;
	this->r = brick.r;
	this->g = brick.g;
	this->b = brick.b;
	this->a = brick.a;
	this->life = brick.life;

	return *this;
}



void Brick::SetX(int x)
{
	this->x = x;
}

void Brick::SetY(int y)
{
	this->y = y;
}

void Brick::SetLife(int life)
{
	this->life = life;
}




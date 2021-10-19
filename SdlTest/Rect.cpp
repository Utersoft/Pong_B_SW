#include "Rect.h"

//Constructeur de rect
Rect::Rect(const Screen& window, int w, int h, int x, int y, int r, int g, int b, int o, int type) :
	Screen(window)
{
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
	this->o = o;
	this->type = type;
}

//Remplissage du rect
void Rect::draw() const
{
	SDL_Rect rect;

	rect.w = w;
	rect.h = h;
	rect.x = x;
	rect.y = y;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(renderer, &rect);
}

//Event du joueur 1 (gauche)
void Rect::pollEvents1(SDL_Event &event)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (event.type == SDL_KEYDOWN) {
		//On vérifie si la touche Z (c'est en qwerty) est en état pressée ou non et si oui, on monte la paddle
		if (keystate[SDL_SCANCODE_W]) {
			if (y >= 0) {
				y -= 20;
			}
		}
		//On vérifie si la touche S est en état pressée ou non et si oui, on descend la paddle
		if (keystate[SDL_SCANCODE_S]) {
			if (y <= SCREEN_HEIGHT - PADDLE_HEIGHT) {
				y += 20;
			}
		}
	}
}

//Event du joueur 2 (droite)
void Rect::pollEvents2(SDL_Event& event)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (event.type == SDL_KEYDOWN) {
		//On vérifie si la fléche haut est en état pressée ou non et si oui, on monte la paddle
		if (keystate[SDL_SCANCODE_UP]) {
			if (y >= 0) {
				y -= 20;
			}
		}
		//On vérifie si la fléche bas est en état pressée ou non et si oui, on descend la paddle
		if (keystate[SDL_SCANCODE_DOWN]) {
			if (y <= SCREEN_HEIGHT - PADDLE_HEIGHT) {
				y += 20;
			}
		}
	}
}

void Rect::SetX(int x)
{
	this->x = x;
}

void Rect::SetY(int y)
{
	this->y = y;
}

int Rect::GetX()
{
	return x;
}

int Rect::GetY()
{
	return y;
}

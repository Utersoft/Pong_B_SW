#include "Rect.h"

//Constructeur de rect
Rect::Rect(const Screen& window, int w, int h, int x, int y, int r, int g, int b, int o) :
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
void Rect::pollEvents(SDL_Event &event, Control &playerInput)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
		//On vérifie si la touche Z (c'est en qwerty) est en état pressée ou non et si oui, on monte la paddle
		if (keystate[SDL_SCANCODE_A]) {
			if (x >= 0) {
				playerInput = Control::KEY_LEFT;
			}
		}
		//On vérifie si la touche S est en état pressée ou non et si oui, on descend la paddle
		if (keystate[SDL_SCANCODE_D]) {
			if (x <= SCREEN_WIDTH - PADDLE_WIDTH) {
				playerInput = Control::KEY_RIGHT;
			}
		}
		if (keystate[SDL_SCANCODE_SPACE]) {
			playerInput = Control::KEY_SHOOT;
		}
	}
	if (event.type == SDL_KEYUP || (x <= 0 && playerInput == Control::KEY_LEFT) || (x >= SCREEN_WIDTH - PADDLE_WIDTH && playerInput == Control::KEY_RIGHT)) {
		playerInput = Control::DEFAULT;
	}

	switch (playerInput){
	case Control::KEY_LEFT:
		x -= PADDLE_SPEED;
		break;
	case Control::KEY_RIGHT:
		x += PADDLE_SPEED;
		break;
	case Control::KEY_SHOOT:
		break;
	case Control::DEFAULT:
		break;
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

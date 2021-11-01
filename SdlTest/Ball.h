#pragma once
#include "Rect.h"
#include "ListeBrick.h"
#define BALLSIZE 30
#define ANGX -4
#define ANGY 2


class Ball : public Rect{
public:
	//Constructeur de Ball
	Ball(const Rect& rect, float flt_spdX, float flt_spdY, SDL_Rect ballColliderBox);
	//Destructeurs de Ball
	~Ball();

	void pollEvents(Rect& paddle, listBrick listOfBrick);
	bool ballCollide(SDL_Rect collisionBox, Brick brick);
	
private:

	float flt_spdX;
	float flt_spdY;
	SDL_Rect ballCollideBox;
};
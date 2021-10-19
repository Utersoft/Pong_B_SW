#pragma once
#include "Rect.h"
#define BALLSIZE 30
#define ANGX -4
#define ANGY 2


class Ball : public Rect{
public:
	//Constructeur de Ball
	Ball(const Rect& rect, float flt_spdX, float flt_spdY, int n_start);
	//Destructeurs de Ball
	~Ball();

	void initBallDirection();
	void pollEvents(int &scoreJ1, int &scoreJ2, Rect &rect1, Rect &rect2);
	bool ballColide(Rect& rect);
	
private:
	float flt_spdX;
	float flt_spdY;
	int n_start;
};
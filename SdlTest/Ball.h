#pragma once
#include "Rect.h"
#define BALLSIZE 30
#define ANGX -5
#define ANGY 2.5


class Ball : public Rect{
public:
	Ball(const Rect& rect, float flt_spdX, float flt_spdY, int n_start);
	~Ball();

	void initBallDirection();
	void pollEvents(int scoreJ1, int scoreJ2, Rect &rect1, Rect &rect2);
	
private:
	float flt_spdX;
	float flt_spdY;
	int n_start;
};
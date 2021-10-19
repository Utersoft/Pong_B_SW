#include "Ball.h"

Ball::Ball(const Rect& rect, float flt_spdX, float flt_spdY, int n_start) :
	Rect(rect)
{
	this->flt_spdX = flt_spdX;
	this->flt_spdY = flt_spdY;
	this->n_start = n_start;
}

Ball::~Ball()
{
}

void Ball::initBallDirection()
{
	this->flt_spdX = this->flt_spdX * n_start;
}

void Ball::pollEvents(int scoreJ1, int scoreJ2, Rect &rect1, Rect &rect2)
{
	if(scoreJ1 < 3 || scoreJ2 < 3) {
		if (this->GetY() < 0 || this->GetY() > SCREEN_HEIGHT - BALLSIZE) {
			flt_spdY = flt_spdY * (-1);
		}
		if (((this->GetX() <= rect1.GetX() + PADDLE_WIDTH && this->GetX() >= rect1.GetX()) || (this->GetX() + BALLSIZE >= rect1.GetX() && this->GetX() + BALLSIZE <= rect1.GetX() + PADDLE_WIDTH)) && (this->GetY() >= rect1.GetY() && this->GetY() <= rect1.GetY() + PADDLE_HEIGHT) && (this->GetY() + BALLSIZE >= rect1.GetY() && this->GetY() + BALLSIZE <= rect1.GetY() + PADDLE_HEIGHT)) {
			flt_spdX = flt_spdX * (-1);
		}
		if (((this->GetX() <= rect2.GetX() + PADDLE_WIDTH && this->GetX() >= rect2.GetX()) || (this->GetX() + BALLSIZE >= rect2.GetX() && this->GetX() + BALLSIZE <= rect2.GetX() + PADDLE_WIDTH)) && (this->GetY() >= rect2.GetY() && this->GetY() <= rect2.GetY() + PADDLE_HEIGHT) && (this->GetY() + BALLSIZE >= rect2.GetY() && this->GetY() + BALLSIZE <= rect2.GetY() + PADDLE_HEIGHT)) {
			flt_spdX = flt_spdX * (-1);
		}
		if (this->GetX() < 0 || this->GetX() > SCREEN_WIDTH - BALLSIZE) {
			if (this->GetX() < 0) {
				scoreJ1++;
			}
			if (this->GetX() > SCREEN_WIDTH - BALLSIZE) {
				scoreJ2++;
			}
			this->SetX(10);
			this->SetY(SCREEN_WIDTH / 2);
		}

		this->SetX(this->GetX() + flt_spdX);
		this->SetY(this->GetY() + flt_spdY);
	}
}

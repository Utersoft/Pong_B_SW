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

//Initialisation de la direction de la balle au début de la game
void Ball::initBallDirection()
{
	this->flt_spdX = this->flt_spdX * n_start;
}

void Ball::pollEvents(int &scoreJ1, int &scoreJ2, Rect &rect1, Rect &rect2)
{
	if(scoreJ1 < 3 && scoreJ2 < 3) {
		//Vérification s'il y a collision avec le plafond ou le bas de l'écran
		if (this->GetY() < 0 || this->GetY() > SCREEN_HEIGHT - BALLSIZE) {
			flt_spdY = flt_spdY * (-1);
		}
		//Vérification du contact avec la raquette de gauche, on le fait partir dans l'autre sens et aller plus viter
		if  (this->ballColide(rect1)){
			flt_spdX = flt_spdX * (-1);
			flt_spdX+=0.2;
			flt_spdY+=0.2;
		}
		//Vérification du contact avec la raquette de droite et si oui, la balle repars dans l'autre sens
		if (this->ballColide(rect2)) {
			flt_spdX = flt_spdX * (-1);
			flt_spdX+=0.2;
			flt_spdY+=0.2;
		}
		//Vérification si la balle sors de la limite. Si oui, le joueur étant du côté où la balle est sortie perd un point et on reset le jeu
		if (this->GetX() < 0 || this->GetX() > SCREEN_WIDTH - BALLSIZE) {
			if (this->GetX() < 0) {
				scoreJ2++;
			}
			if (this->GetX() > SCREEN_WIDTH - BALLSIZE) {
				scoreJ1++;
			}
			this->SetX(SCREEN_WIDTH / 2);
			this->SetY(0);
			flt_spdX = ANGX;
			flt_spdY = ANGY;
			rect1.SetX(SCREEN_WIDTH * 0.01);
			rect1.SetY(SCREEN_HEIGHT / 2);
			rect2.SetX(SCREEN_WIDTH * 0.978);
			rect2.SetY(SCREEN_HEIGHT / 2);
			SDL_Delay(1000);
		}
		
		//Mouvement de la balle
		this->SetX(this->GetX() + flt_spdX);
		this->SetY(this->GetY() + flt_spdY);
	}
	else {
		//Reset du score après un laps de 5 sec
		SDL_Delay(5000);
		scoreJ1 = 0;
		scoreJ2 = 0;
	}
}


//Fonction de détection de la collision de la balle avec les raquettes (paddle)
bool Ball::ballColide(Rect& rect)
{
	return (((this->GetX() <= rect.GetX() + PADDLE_WIDTH && this->GetX() >= rect.GetX()) || (this->GetX() + BALLSIZE >= rect.GetX() && this->GetX() + BALLSIZE <= rect.GetX() + PADDLE_WIDTH)) && (this->GetY() >= rect.GetY() && this->GetY() <= rect.GetY() + PADDLE_HEIGHT) && (this->GetY() + BALLSIZE >= rect.GetY() && this->GetY() + BALLSIZE <= rect.GetY() + PADDLE_HEIGHT));
}

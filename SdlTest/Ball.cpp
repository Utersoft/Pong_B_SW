#include "Ball.h"

Ball::Ball(const Rect& rect, float flt_spdX, float flt_spdY, SDL_Rect ballColliderBox) :
	Rect(rect)
{
	this->flt_spdX = flt_spdX;
	this->flt_spdY = flt_spdY;
	this->ballCollideBox.w = ballColliderBox.w;
	this->ballCollideBox.h = ballColliderBox.h;
}

Ball::~Ball()
{
}


void Ball::pollEvents(Rect &paddle, listBrick listOfBrick)
{
	if(0) {
		//Vérification s'il y a collision avec le plafond ou le bas de l'écran
		if (this->GetY() < 0) {
			flt_spdY = flt_spdY * (-1);
		}
		//Vérification du contact avec la raquette de gauche, on le fait partir dans l'autre sens et aller plus viter
		/*if (this->ballColide(rect1)) {
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
		scoreJ2 = 0;*/
	}
}


//Fonction de détection de la collision de la balle avec les raquettes (paddle)
bool Ball::ballCollide(SDL_Rect collisionBox, Brick brick)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = collisionBox.x;
	rightA = collisionBox.x + collisionBox.w;
	topA = collisionBox.y;
	bottomA = collisionBox.y + collisionBox.h;

	leftB = brick.GetX();
	rightB = brick.GetX() + brick.GetW();
	topB = brick.GetY();
	bottomB = brick.GetY() + brick.GetH();


	if (bottomA <= topB) {
		return false;
	}
	if (topA >= bottomB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}

	return true;
}

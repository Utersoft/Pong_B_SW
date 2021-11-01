#include "ListeBrick.h"

listBrick::listBrick()
{
	pFirstBrick = nullptr;
	pCurrentBrick = pFirstBrick;
}

listBrick::~listBrick()
{
	brickElement* pNextBrickTemp;
	pCurrentBrick = pFirstBrick;
	while (pCurrentBrick != nullptr) {
		pNextBrickTemp = pCurrentBrick->pNextBrick;
		delete pCurrentBrick;
		pCurrentBrick = pNextBrickTemp;
	}
}

void listBrick::firstBrick()
{
	pCurrentBrick = pFirstBrick;
}

Brick listBrick::initBrick(int n_i, int n_j)
{
	Brick pBrick(1, BRICK_WIDTH, BRICK_HEIGHT, BRICK_ORIGIN_X + (2 + (BRICK_WIDTH * n_j)), BRICK_ORIGIN_Y + (2 + (BRICK_HEIGHT * n_i)), 255, 255, 255, 0);
	return pBrick;
}

void listBrick::initListBrick(Brick brick[BRICK_NUMBER_LENGTH * BRICK_NUMBER_WIDTH])
{
	int n_i = 0, n_j = 0, cpt = 0;

	srand(time(NULL));

	int n_vieRandom;

	for (n_i = 0; n_i < BRICK_NUMBER_LENGTH; n_i++) {
		brick[cpt].SetX(BRICK_ORIGIN_X);
		for (n_j = 0; n_j < BRICK_NUMBER_WIDTH; n_j++) {
			n_vieRandom = rand() % 100 + 1;
			if (pFirstBrick != nullptr && n_j != 0) {
				brick[cpt].SetX(this->pFirstBrick->brick->GetX() + BRICK_WIDTH + BRICK_SPACING);
				brick[cpt].SetY(this->pFirstBrick->brick->GetY());
			}
			if (n_vieRandom < 70) {
				brick[cpt].SetLife(1);
			}
			else if (n_vieRandom >= 70 && n_vieRandom < 90) {
				brick[cpt].SetLife(2);
			}
			else {
				brick[cpt].SetLife(3);
			}
			addBrick(&brick[cpt], cpt);
			cpt++;
		}
		brick[cpt].SetY(this->pFirstBrick->brick->GetY() + BRICK_HEIGHT + BRICK_SPACING);
	}
}

void listBrick::addBrick(Brick *brick, int ID)
{
	brickElement* newBrickElement = new brickElement;
	newBrickElement->pNextBrick = pFirstBrick;
	newBrickElement->n_IdBrick = ID;
	newBrickElement->brick = brick;
	pFirstBrick = newBrickElement;
}

void listBrick::drawList(SDL_Renderer *renderer)
{
	Brick *brickTemp = pFirstBrick->brick;
	firstBrick();
	while (pCurrentBrick != nullptr) {
		brickTemp = pCurrentBrick->brick;
		brickTemp->draw(renderer);
		pCurrentBrick = pCurrentBrick->pNextBrick;
	}
}



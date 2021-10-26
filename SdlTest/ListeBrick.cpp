#include "ListeBrick.h"

listBrick::listBrick(const Screen& screen) :
	Screen(screen)
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

void listBrick::initListBrick(Screen& pWindow)
{
	int n_i = 0, n_j = 0, cpt = 0;


	for (n_i = 0; n_i < BRICK_NUMBER_LENGTH; n_i++) {
		for (n_j = 0; n_j < BRICK_NUMBER_WIDTH; n_j++) {
			Brick pBrick(pWindow, 1, BRICK_WIDTH, BRICK_HEIGHT, BRICK_ORIGIN_X + (2 + (BRICK_WIDTH * n_j)), BRICK_ORIGIN_Y + (2 + (BRICK_HEIGHT * n_i)), 255, 255, 255, 0);
			this->addBrick(&pBrick, cpt);
			cpt++;
		}
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

void listBrick::drawList()
{
	firstBrick();
	while (pCurrentBrick != nullptr) {
		pCurrentBrick->brick->draw();
		pCurrentBrick = pCurrentBrick->pNextBrick;
	}
}



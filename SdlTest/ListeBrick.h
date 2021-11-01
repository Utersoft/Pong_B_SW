#pragma once
#include "Brick.h"
#include <time.h>


typedef struct brickElement {
	Brick *brick;
	brickElement *pNextBrick;
	int n_IdBrick;
}brickElement;


class listBrick {
private:
	brickElement* pCurrentBrick;
	brickElement* pFirstBrick;
public:
	listBrick();
	~listBrick();
	void firstBrick();
	Brick initBrick(int n_i, int n_j);
	void initListBrick(Brick brick[BRICK_NUMBER_LENGTH * BRICK_NUMBER_WIDTH]);
	void addBrick(Brick *brick, int ID);
	void drawList(SDL_Renderer *renderer);
};
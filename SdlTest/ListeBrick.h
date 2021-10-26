#pragma once
#include "Brick.h"


typedef struct brickElement {
	Brick *brick;
	brickElement *pNextBrick;
	int n_IdBrick;
}brickElement;


class listBrick : public Screen{
private:
	brickElement* pCurrentBrick;
	brickElement* pFirstBrick;

public:
	listBrick(const Screen& screen);
	~listBrick();
	void firstBrick();
	void initListBrick(Screen& pWindow);
	void addBrick(Brick *brick, int ID);
	void drawList();

};
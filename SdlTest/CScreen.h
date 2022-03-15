#pragma once

#include "SDL.h"
#include "CTexture.h"
#include <iostream>
#include <string>
#include <fstream>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;
const int TILE_SIZE = 20;

using namespace std;

class CScreen {
private :
	bool isRunning;

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	CTexture pTexture;

	int n_map[SCREEN_HEIGHT / TILE_SIZE][SCREEN_WIDTH / TILE_SIZE];

public:
	//Constructeur
	CScreen();

	//Initialisation
	bool init(const char* title, int n_xPos, int n_yPos, int n_flag);
	void render();
	void handleEvents();
	void clean();

	//Accesseur
	bool getIsRunning() { return isRunning; };

	//Mutateur
	void setIsRunning(bool isRunning) { this->isRunning = isRunning; };
};
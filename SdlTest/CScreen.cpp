#include "CScreen.h"

CScreen::CScreen()
{
	isRunning = true;

	pWindow = NULL;
	pRenderer = NULL;

	//Initialisation du tableau de valeur du tilemap à 0
	for (int n_i = 0; n_i < SCREEN_HEIGHT / TILE_SIZE; n_i++) {
		for (int n_j = 0; n_j < SCREEN_WIDTH / TILE_SIZE; n_j++) {
			n_map[n_i][n_j] = 0;
		}
	}
}

bool CScreen::init(const char* title, int n_xPos, int n_yPos, int n_flag)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		pWindow = SDL_CreateWindow(title, n_xPos, n_yPos, SCREEN_WIDTH, SCREEN_HEIGHT, n_flag);
		if (pWindow != 0) {
			std::cout << "window creation success\n";
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);
			if (pRenderer != 0) {
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false;
	}
	isRunning = true;

	ifstream pMap;
	pTexture.loadImage("./Assets/tilemapTest.png", "tile", pRenderer);
	pMap.open("Map.txt");

	//Récupération des données du tile contenu dans le tableau
	for (int n_i = 0; n_i < 10; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			pMap >> n_map[n_i][n_j];
		}
	}
	pMap.close();
	std::cout << "init success\n";

	return true;
}

void CScreen::render()
{
	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(pRenderer);

	//On rempli la texture avec les tiles récupérées
	for (int n_i = 0; n_i < 10; n_i++) {
		for (int n_j = 0; n_j < 15; n_j++) {
			pTexture.drawTile("tile", n_j, n_i, TILE_SIZE, TILE_SIZE, pRenderer, n_map[n_i][n_j], 16);
		}
	}
	//Affichage
	SDL_RenderPresent(pRenderer);
}

void CScreen::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				//On ferme la fenêtre si on appuie sur la touche echap
				isRunning = false;
				break;
			}
		}
	}
}

void CScreen::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
}

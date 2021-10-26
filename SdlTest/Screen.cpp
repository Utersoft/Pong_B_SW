#include "Screen.h"


//Constructeur d'�cran
Screen::Screen(const string& title, int screenWidth, int screenHeight) {
	this->title = title;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;

	closed = !initScreen();
}

/*Screen::Screen()
{
	title = "";
	screenWidth = 0;
	screenHeight = 0;
}*/


//Destructeur d'�cran
Screen::~Screen()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Gestion des �v�nement de l'�cran
void Screen::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	//Fermeture de la fen�tre avec la croix
	case SDL_QUIT:
		closed = true;
		break;
	//V�rification si une touche est press�e
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		//Si on appuie sur escape, on met true pour la fermeture
		case SDLK_ESCAPE:
			closed = true;
			break;
		}
	default:
		break;
	}
}

//Affichage des formes et du fond d'�cran
void Screen::clearScreen()
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}


//Initialisation des �l�ments de l'�crans
bool Screen::initScreen()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stdout, "�chec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return 0;
	}

	//Cr�ation de la fen�tre (taille, position, titre)
	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight,
		0
	);

	if (window == NULL) {
		fprintf(stderr, "Erreur de cr�ation de la fen�tre: %s\n", SDL_GetError());
		return 0;
	}

	//Cr�ation du renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		fprintf(stderr, "Erreur de cr�ation du renderer : %s\n", SDL_GetError());
		return 0;
	}

	return true;
}

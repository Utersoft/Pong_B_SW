#include "Screen.h"


//Constructeur d'écran
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


//Destructeur d'écran
Screen::~Screen()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

//Gestion des événement de l'écran
void Screen::pollEvents(SDL_Event &event)
{
	switch (event.type) {
	//Fermeture de la fenêtre avec la croix
	case SDL_QUIT:
		closed = true;
		break;
	//Vérification si une touche est pressée
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

//Affichage des formes et du fond d'écran
void Screen::clearScreen()
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}


//Initialisation des éléments de l'écrans
bool Screen::initScreen()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
		return 0;
	}

	//Création de la fenêtre (taille, position, titre)
	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight,
		0
	);

	if (window == NULL) {
		fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
		return 0;
	}

	//Création du renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		fprintf(stderr, "Erreur de création du renderer : %s\n", SDL_GetError());
		return 0;
	}

	return true;
}

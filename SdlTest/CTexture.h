#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <map>

class CTexture {
private:
	std::map<std::string, SDL_Texture*> textureMap;

public:
	//Constructeur
	CTexture();

	//Permet de charger l'image
	bool loadImage(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	//Permet de dessiner l'image dans le renderer
	void drawImage(std::string id, int n_x, int n_y, int n_width, int n_height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawTile(std::string id, int n_x, int n_y, int n_width, int n_height, SDL_Renderer* pRenderer, int n_nbTile, int n_widthTM, SDL_RendererFlip flip = SDL_FLIP_NONE);
};
#include "CTexture.h"

CTexture::CTexture()
{
}

//Charge une image d'une liste
bool CTexture::loadImage(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0) {
		return false;
	}

	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);

	if (pTexture != 0) {
		textureMap[id] = pTexture;
		return true;
	}

    return false;
}

//Affiche la texture
void CTexture::drawImage(std::string id, int n_x, int n_y, int n_width, int n_height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect destRect;

	destRect.w = n_width;
	destRect.h = n_height;
	destRect.x = n_x;
	destRect.y = n_y;
	SDL_RenderCopyEx(pRenderer, textureMap[id], NULL, &destRect, 0, 0, flip);
}

void CTexture::drawTile(std::string id, int n_x, int n_y, int n_width, int n_height, SDL_Renderer* pRenderer, int n_nbTile, int n_widthTM, SDL_RendererFlip flip)
{
	SDL_Rect destRect;
	SDL_Rect srcRect;

	destRect.w = srcRect.w = n_width;
	destRect.h = srcRect.h = n_height;
	destRect.x = n_x * n_width;
	destRect.y = n_y * n_width;
	
	srcRect.x = (n_nbTile % n_widthTM) * n_width;
	srcRect.y = n_nbTile / n_widthTM * n_width;

	SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

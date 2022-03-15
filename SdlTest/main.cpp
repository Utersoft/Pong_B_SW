#include "CScreen.h"
#include "SDL.h"
#include "SDL_image.h"


int main(int argc, char** argv)
{
	CScreen pGameWindow;

	pGameWindow.init("Jeu", 100, 100, 0);

	//Tant que IsRunning est True, on garde la fenêtre ouverte
	while (pGameWindow.getIsRunning()) {
		pGameWindow.handleEvents();
		pGameWindow.render();
		SDL_Delay(1000 / 60);
	}
	pGameWindow.clean();

    return 0;
}

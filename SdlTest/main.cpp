#include <stdio.h>
#include "Screen.h"
#include "Rect.h"
#include "Ball.h"



//prototype
void pollEvents(Screen& window, Rect& rect, Control& playerInput);


int main(int argc, char** argv)
{
    Screen pWindow("Pong en SDL", SCREEN_WIDTH, SCREEN_HEIGHT);
    Rect paddleRect(pWindow, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH / 2, (SCREEN_HEIGHT - 10) - PADDLE_HEIGHT,  255, 255, 255, 0);
    Control playerInput = Control::DEFAULT;

    //Boucle principale du jeu.
    //Contient tous les events du jeu ainsi que l'affichage des �l�ments du jeu (raquettes, balle, gestions des touches)
    while (!pWindow.isClosed()) {
        pollEvents(pWindow, paddleRect, playerInput);
        paddleRect.draw();
        pWindow.clearScreen();
        SDL_Delay(10);
    }


    return 0;
}

//Fonction pollEvents qui regroupent les event de la fen�tre et des deux paddles
void pollEvents(Screen& window, Rect& rect, Control &playerInput) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        rect.pollEvents(event, playerInput);

        window.pollEvents(event);
    }
}
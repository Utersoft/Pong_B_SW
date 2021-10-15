#include <stdio.h>
#include "Screen.h"
#include "Rect.h"



//prototype
void pollEvents(Screen& window, Rect& rect1, Rect &rect2);


int main(int argc, char** argv)
{
    Screen pWindow("Pong en SDL", SCREEN_WIDTH, SCREEN_HEIGHT);
    Rect leftPaddleRect(pWindow, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH * 0.01, SCREEN_HEIGHT / 2,  255, 255, 255, 0, 1);
    Rect rightPaddleRect(pWindow, PADDLE_WIDTH, PADDLE_HEIGHT, SCREEN_WIDTH * 0.978, SCREEN_HEIGHT / 2,  255, 255, 255, 0, 2);
    Rect ballRect(pWindow, 30, 30, SCREEN_WIDTH / 2, 0, 255, 255, 255, 0, 0);

    while (!pWindow.isClosed()) {
        pollEvents(pWindow, leftPaddleRect, rightPaddleRect);
        leftPaddleRect.draw();
        rightPaddleRect.draw();
        ballRect.draw();
        pWindow.clearScreen();
    }


    return 0;
}

//Fonction pollEvents qui regroupent les event de la fenêtre et des deux paddles
void pollEvents(Screen& window, Rect& rect1, Rect &rect2) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (rect1.type == 1) {
            rect1.pollEvents1(event);
        }
        if (rect2.type == 2) {
            rect2.pollEvents2(event);
        }

        window.pollEvents(event);
    }
}
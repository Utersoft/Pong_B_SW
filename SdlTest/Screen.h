#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750
#define PADDLE_HEIGHT 100
#define PADDLE_WIDTH 20

using namespace std;


class Screen {
public:
	//Constructeur
	Screen(const string& title, int screenWidth, int screenHeight);
	//Destructeur
	~Screen();
	

	void pollEvents(SDL_Event &event);
	void clearScreen();


	inline bool isClosed() const { return closed;  }

private:
	bool initScreen();

	string title;
	int screenWidth;
	int screenHeight;

	bool closed = false;


protected:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
};
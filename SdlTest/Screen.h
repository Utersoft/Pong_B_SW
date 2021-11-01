#pragma once
#include <string>
#include <iostream>
#include <SDL.h>
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 750
#define PADDLE_HEIGHT 20
#define PADDLE_WIDTH 100
#define PADDLE_SPEED 6
#define BRICK_NUMBER_LENGTH 6
#define BRICK_NUMBER_WIDTH 12
#define BRICK_WIDTH 100
#define BRICK_HEIGHT 40
#define BRICK_ORIGIN_X 100
#define BRICK_ORIGIN_Y 60
#define BRICK_SPACING 8

enum class Control {
	DEFAULT,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_SHOOT
};

using namespace std;


class Screen {
public:
	//Constructeurs
	Screen();
	Screen(const string& title, int screenWidth, int screenHeight);
	//Destructeur
	~Screen();
	

	void pollEvents(SDL_Event &event);
	void clearScreen();


	inline bool isClosed() const { return closed;  }

	SDL_Renderer* renderer = NULL;

private:
	bool initScreen();

	string title;
	int screenWidth;
	int screenHeight;

	bool closed = false;

	

protected:
	SDL_Window* window = NULL;
	
};
#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_main.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	bool isPaused() { return paused; }

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
private:
	bool isRunning = false;
	bool paused = false;
	bool drawing = false;

	uint32_t cnt = 0;
	SDL_Window* window;
};
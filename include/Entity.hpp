#pragma once

#include "Game.hpp"
#include "TextureManager.hpp"

class Entity {
protected:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;

	SDL_Rect srcRect;
	SDL_Rect destRect;
public:
	Entity(const char* texturesheet, int x, int y);
	Entity() {
		xpos = 0;
		ypos = 0;
		Update();
	}
	~Entity() {}

	virtual void Update();
	virtual void Render();
};
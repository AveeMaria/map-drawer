#pragma once

#include "Game.hpp"

class Map {
public:
    Map();
    ~Map();

    void LoadMap(short arr[40][60]);
    void DrawMap();

    void paintValue(short x, short y);
    void printMap();

    short value = 0;
private:
    SDL_Rect src, dest;

    SDL_Texture* water;
    SDL_Texture* sand;
    SDL_Texture* grass;
    SDL_Texture* forest;

    short map[40][60];
};
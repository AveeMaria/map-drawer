#include "../include/Game.hpp"
#include "../include/TextureManager.hpp"
#include "../include/Entity.hpp"
#include "../include/Map.hpp"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    //if (SDL_Init(SDL_INIT_EVERYTHING) == 0)//
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == 0)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    map = new Map();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                drawing = true;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT) {
                drawing = false;
            }
            break;
        default:
            break;
        }
    }

    // If the mouse is held down, get its position and add points
    if (drawing) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        map->paintValue(mouseX, mouseY);
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
    if (currentKeyStates[SDL_SCANCODE_1]) {
        map->value = 0;
    }
    if (currentKeyStates[SDL_SCANCODE_2]) {
        map->value = 1;
    }
    if (currentKeyStates[SDL_SCANCODE_3]) {
        map->value = 2;
    }
    if (currentKeyStates[SDL_SCANCODE_4]) {
        map->value = 3;
    }
    if (currentKeyStates[SDL_SCANCODE_M]) {
        map->printMap();
    }
}

void Game::update() {

}

void Game::render() {
    SDL_RenderClear(renderer);

    map->DrawMap();
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "game cleaned\n";
}
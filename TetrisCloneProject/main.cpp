#include <SDL.h>
#include <stdio.h>
#include <vector>

#include "gameObject.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SDL_Rect playArea = { 230, 40, 200, 400 };

    // Main loop
    bool quit = false;
    SDL_Event e;

    
    std::vector<std::unique_ptr<gameObject>> gameObjects;
    
    gameObjects.push_back(std::make_unique<gameObject>(330, 40, 10, 10, 1.0f,"Rectangle"));
    for (auto& gameObj : gameObjects)
    {
        std::cout << "Object found, initialized with parameters(x,y,w,h,velocity):"; gameObj->getObjInfo();
    }
    bool createObject = false;
    while (!quit)
    {
        if (createObject)
        {
            gameObjects.push_back(std::make_unique<gameObject>(330, 40, 10, 10, 1.0f, "Rectangle"));
            std::cout << "Object created" << "\n";
 
            createObject = false;
        }
        // Handle events
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Clear screen (fill with black)
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        // Draw white rectangle
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawRect(renderer, &playArea);

        for (auto& gameObj : gameObjects) {
            gameObj->checkPos();
            gameObj->update();
        }

        for (auto& gameObj : gameObjects) {
            gameObj->render(renderer);
        }

       
        // Update screen
        SDL_RenderPresent(renderer);

        SDL_Delay(20);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
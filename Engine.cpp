#include "Engine.h"

void Engine::run() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Particles of Life", 640, 480, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, nullptr);

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not open window: %s\n", SDL_GetError());
    }

    while (running) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Engine logic here



        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

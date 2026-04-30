#include "Engine.hpp"

void Engine::run() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Particles of Life", 640, 480, SDL_WINDOW_OPENGL);

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

        // Engine logic here
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

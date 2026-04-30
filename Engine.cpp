#include "Engine.h"

void Engine::run() {
    init();
    loop();
    cleanup();
}

void Engine::init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Particles of Life", window_width, window_height, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, nullptr); // renderer will be moved into its own class but for now it lives here

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not open window: %s\n", SDL_GetError());
    }

    world.initializeParticles();
}

void Engine::loop() {
    // handle events → update simulation → render
    while (running) {
        handleEvents();
        // update() the particles will go here
        render();
    }
}

void Engine::render() {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw logic here
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);


    SDL_FRect rects[world.particle_count];
    for (int i = 0; i < world.particle_count; i++) {
        rects[i] = SDL_FRect{world.particles[i].x, world.particles[i].y, 6, 6}; // 6 will change to a variable "particle size"
    }

    SDL_RenderFillRects(renderer, rects, world.particle_count);

    // Draw screen
    SDL_RenderPresent(renderer);
}

void Engine::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Engine::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;

            case SDL_EVENT_KEY_DOWN:
                switch (event.key.key) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                }
        }
    }
}

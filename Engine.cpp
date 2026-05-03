#include "Engine.h"

void Engine::run() {
    init();
    loop();
}

void Engine::init() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Particles of Life", window_width, window_height, SDL_WINDOW_OPENGL);
    renderer.init(window);
    world.initWorld(window_width, window_height, 1000);

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not open window: %s\n", SDL_GetError());
    }
}

void Engine::loop() {
    // handle events → update simulation → render
    Uint64 last = SDL_GetPerformanceCounter();
    double deltaTime = 0.0;

    while (running) {
        Uint64 now = SDL_GetPerformanceCounter();
        deltaTime = (double)((now - last) / (double)SDL_GetPerformanceFrequency()) * 60;
        last = now;

        handleEvents();
        world.update(deltaTime);
        renderer.render(world);
    }
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

Engine::~Engine() {
    SDL_DestroyWindow(window);
    window = nullptr;

    SDL_Quit();
}

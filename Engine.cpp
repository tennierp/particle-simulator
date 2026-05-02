#include "Engine.h"

void Engine::run() {
    init();
    loop();
}

void Engine::init() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Particles of Life", window_width, window_height, SDL_WINDOW_OPENGL);
    renderer.init(window, world.getParticleCount());
    world.initializeParticles();

    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not open window: %s\n", SDL_GetError());
    }
}

void Engine::loop() {
    // handle events → update simulation → render
    while (running) {
        handleEvents();
        world.update();
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

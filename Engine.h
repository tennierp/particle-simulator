#ifndef PARTICLE_SIMULATOR_ENGINE_H
#define PARTICLE_SIMULATOR_ENGINE_H
#include <SDL3/SDL.h>
#include "Render.h"
#include "World.h"

class Engine {
public:
    void init();
    void run();
    void loop();
    void handleEvents();

    ~Engine();

private:
    const int window_width = 1200;
    const int window_height = 800;
    SDL_Window *window{};
    Render renderer{};
    World world{}; // particle count is hardcoded here
    double deltaTime = 0.0;
    bool running = true;
};

#endif //PARTICLE_SIMULATOR_ENGINE_H
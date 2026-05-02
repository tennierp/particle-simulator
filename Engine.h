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
    const int window_width = 1024;
    const int window_height = 720;
    SDL_Window *window{};
    Render renderer{};
    World world{}; // particle count is hardcoded here
    bool running = true;
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

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
    bool running = true;
    const int window_height = 720;
    SDL_Window *window{};
    Render renderer;
    World world{(float)window_width, (float)window_height, 500};
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

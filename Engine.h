#ifndef PARTICLE_SIMULATOR_ENGINE_H
#define PARTICLE_SIMULATOR_ENGINE_H
#include <SDL3/SDL.h>
#include "Render.h"
#include "World.h"

class Engine {
    public:
        SDL_Window *window{};
        const int window_width = 1024;
        const int window_height = 720;

        void init();
        void run();
        void loop();
        void handleEvents();

        ~Engine();

    private:
        World world{(float)window_width, (float)window_height, 100};
        Render renderer;
        bool running = true;
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

#ifndef PARTICLE_SIMULATOR_ENGINE_H
#define PARTICLE_SIMULATOR_ENGINE_H
#include <SDL3/SDL.h>

class Engine {
    public:
        bool running = true;
        void run();

    private:
        SDL_Window *window{};
        SDL_Renderer *renderer{};
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

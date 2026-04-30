#ifndef PARTICLE_SIMULATOR_ENGINE_HPP
#define PARTICLE_SIMULATOR_ENGINE_HPP
#include <SDL3/SDL.h>

class Engine {
    public:
        bool running = true;
        void run();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

};

#endif //PARTICLE_SIMULATOR_ENGINE_HPP

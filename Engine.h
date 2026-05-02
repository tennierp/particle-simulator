#ifndef PARTICLE_SIMULATOR_ENGINE_H
#define PARTICLE_SIMULATOR_ENGINE_H
#include <SDL3/SDL.h>
#include "World.h"

class Engine {
    public:
        const int window_width = 1024;
        const int window_height = 720;

        void init();
        void run();
        void loop();
        void render();
        void cleanup();
        void handleEvents();

    private:
        SDL_Window *window{};
        SDL_Renderer *renderer{};
        std::vector<SDL_FRect> rects;

        World world{(float)window_width, (float)window_height, 100};
        bool running = true;
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

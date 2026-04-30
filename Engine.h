#ifndef PARTICLE_SIMULATOR_ENGINE_H
#define PARTICLE_SIMULATOR_ENGINE_H
#include <SDL3/SDL.h>

class Engine {
    public:
        const int WINDOW_WIDTH = 640;
        const int WINDOW_HEIGHT = 480;

        void initWindow();
        void run();
        void loop();
        void render();
        void cleanup();
        void handleEvents();

    private:
        SDL_Window *window{};
        SDL_Renderer *renderer{};

        bool running = true;
};

#endif //PARTICLE_SIMULATOR_ENGINE_H

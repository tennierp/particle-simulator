#ifndef PARTICLE_SIMULATOR_RENDER_H
#define PARTICLE_SIMULATOR_RENDER_H
#include <SDL3/SDL.h>
#include <vector>
#include "World.h"

class Render {
public:
    void init(SDL_Window *window);
    void render(World &world);

    ~Render();
private:
    SDL_Renderer *renderer {};
};

#endif //PARTICLE_SIMULATOR_RENDER_H

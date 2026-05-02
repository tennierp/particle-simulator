#include "Render.h"

SDL_Color COLORS[5] = {
        {255, 0, 0, 255},    // red
        {255, 150, 50, 255}, // orange
        {255, 225, 50, 255}, // yellow
        {0, 255, 0, 255},    // green
        {0, 0, 255, 255},    // blue
};

void Render::init(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, nullptr);
}

void Render::render(World &world) {
    // Clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw logic here
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    std::vector<Particle> particles = world.getParticles();
    std::vector<SDL_FRect> rects {};
    rects.reserve(world.getParticleCount());

    for (int i = 0; i < world.getParticleCount(); i++) {
        rects.push_back(SDL_FRect{particles[i].position.x, particles[i].position.y, 6, 6});
    }

    SDL_RenderFillRects(renderer, rects.data(), world.getParticleCount());

    // Draw screen
    SDL_RenderPresent(renderer);
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

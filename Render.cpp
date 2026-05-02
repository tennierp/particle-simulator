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

    // Draw logic
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    std::vector<Particle> particles = world.getParticles();
    std::vector<SDL_FRect> rects {};
    rects.reserve(world.getParticleCount());

    // Use batching to spawn each color particle all at once
    std::vector<SDL_FRect> typeRects[5];

    for (int i = 0; i < world.getParticleCount(); i++) {
        typeRects[particles[i].type].push_back(SDL_FRect{particles[i].position.x, particles[i].position.y, 4, 4}); // Particle size is still hardcoded here
    }

    for (int i = 0; i < 5; i++) {
        SDL_SetRenderDrawColor(renderer, COLORS[i].r, COLORS[i].g, COLORS[i].b, 255);
        SDL_RenderFillRects(renderer, typeRects[i].data(), typeRects[i].size());
    }

    // Draw screen
    SDL_RenderPresent(renderer);
}

Render::~Render() {
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
}

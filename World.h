#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"

class World {
    public:
        World(float width, float height) : worldWidth(width), worldHeight(height) {}
        void initializeParticles();
        void create();
        Particle particles{};
    private:
        float worldHeight{};
        float worldWidth{};
};


#endif //PARTICLE_SIMULATOR_WORLD_H

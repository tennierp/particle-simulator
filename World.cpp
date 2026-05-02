#include "World.h"

void World::initializeParticles() {
    std::uniform_real_distribution<float> randX(0, world_width);
    std::uniform_real_distribution<float> randY(0, world_height);

    for (int i = 0; i < particle_count; i++) {
        Particle p{randX(rng), randY(rng)};
        particles.push_back(p);
    }
}

int World::getParticleCount() const {
    return particle_count;
}

std::vector<Particle> World::getParticles() {
    return particles;
}
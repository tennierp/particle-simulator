#include "World.h"

void World::initializeParticles() {
    std::uniform_real_distribution<> randX(0, world_width);
    std::uniform_real_distribution<> randY(0, world_height);

    for (int i = 0; i < particle_count; i++) {
        Particle p{static_cast<float>(randX(rng)), static_cast<float>(randY(rng))};
        particles.push_back(p);
    }
}

void World::create() {

}

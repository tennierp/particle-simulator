#include "World.h"
#include <random>

void World::initializeParticles() {
    std::random_device rd;  // Non-deterministic seed
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_real_distribution<float> randX(0, worldWidth);
    std::uniform_real_distribution<float> randY(0, worldHeight);

    particles.x = randX(gen);
    particles.y = randY(gen);
}

void World::create() {

}

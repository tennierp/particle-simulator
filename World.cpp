#include "World.h"
#include <random>

std::random_device rd;  // Non-deterministic seed
std::mt19937 gen(rd()); // Mersenne Twister engine
std::uniform_int_distribution<> randomize(640, 480); // Range [WINDOW_WIDTH, WINDOW_HEIGHT]

void World::initializeParticles() {
    particles.x = randomize(gen);
    particles.y = randomize(gen);
}

void World::create() {

}

#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"
#include <vector>
#include <random>

class World {
    public:
        World(float width, float height, int p_amount) : world_width(width), world_height(height), particle_count(p_amount) {}

        void initializeParticles(); // constructor and initializing should be in order of the class variables below, not random.
        void create();

        std::vector<Particle> particles{}; // add getParticles() function instead of publicly allowing them
        const int particle_count;

    private:
        float world_height{};
        float world_width{};
        std::mt19937 rng{std::random_device{}()};
};


#endif //PARTICLE_SIMULATOR_WORLD_H

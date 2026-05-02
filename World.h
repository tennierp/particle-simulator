#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"
#include <vector>
#include <random>

class World {
    public:
        World(float width, float height, int p_amount) : world_width(width), world_height(height), particle_count(p_amount) {}

        void initializeParticles();
        int getParticleCount() const;
        std::vector<Particle> getParticles();

    private:
        std::vector<Particle> particles{};
        float world_width{};
        float world_height{};
        const int particle_count;

        std::mt19937 rng{std::random_device{}()};
};


#endif //PARTICLE_SIMULATOR_WORLD_H

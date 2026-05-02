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
    const std::vector<Particle> &getParticles() const;
    void update();

private:
    std::vector<Particle> particles{};
    float world_width{};
    float world_height{};
    const int particle_count;
    static const int numTypes = 5;
    float forces[numTypes][numTypes]{};
    float minDistances[numTypes][numTypes]{};
    float radii[numTypes][numTypes]{};

    std::mt19937 rng{std::random_device{}()};
};


#endif //PARTICLE_SIMULATOR_WORLD_H

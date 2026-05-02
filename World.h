#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"
#include <vector>

class World {
public:
    void initWorld(int world_width, int world_height, int particle_count);
    int getParticleCount() const;
    const std::vector<Particle> &getParticles() const;
    void update();

private:
    std::vector<Particle> particles{};
    int world_width{};
    int world_height{};
    int particle_count{};
    static const int numTypes = 8;
    float forces[numTypes][numTypes]{};
    float minDistances[numTypes][numTypes]{};
    float radii[numTypes][numTypes]{};
};

#endif //PARTICLE_SIMULATOR_WORLD_H

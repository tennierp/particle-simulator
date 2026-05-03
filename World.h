#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"
#include <vector>


class World {
public:
    void initWorld(int world_width, int world_height, int particle_count);
    int getParticleCount() const;
    const std::vector<Particle> &getParticles() const;
    void update(double deltaTime);

//    std::vector<std::vector<int>> grid;
//    int gridWidth = world_width / gridSize;
//    int gridHeight = world_height / gridSize;
//    so grid[gridHeight][gridWidth] will hold the particles positions?

private:
    std::vector<Particle> particles{};
    int world_width{};
    int world_height{};
    int particle_count{};
    static const int numTypes = 8;
    float forces[numTypes][numTypes]{};
    float minDistances[numTypes][numTypes]{};
    float maxInteractionDist[numTypes][numTypes]{};


    static const int maxInteractionRange = 100;
    int gridSize = maxInteractionRange;
    int gridWidth{};
    int gridHeight{};
    std::vector<std::vector<std::vector<int>>> gridCells;
};

#endif //PARTICLE_SIMULATOR_WORLD_H

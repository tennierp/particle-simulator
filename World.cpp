#include "World.h"
#include <algorithm>

// TODO: Print tables or GUI for force/minDistance/maxInteractionDist matrices
// TODO: Clean up unnecessary private variables in World.h
// TODO: Add force K and friction variables to private variables in World.h

void World::initWorld(int width, int height, int amount) {
    world_width = width;
    world_height = height;
    gridWidth = world_width / gridSize;
    gridHeight = world_height / gridSize;
    particle_count = amount;
    gridCells.resize(gridHeight, std::vector<std::vector<int>>(gridWidth));
    Randomizer rand;

    for (int i = 0; i < particle_count; i++) {
        Particle p{rand.randomFloat(0, world_width), rand.randomFloat(0, world_height)};
        p.velocity += 0;
        p.type = rand.randomInt(0, 7);
        particles.push_back(p);
    }

    for (int row = 0; row < numTypes; row++) {
        for (int col = 0; col < numTypes; col++) {
            forces[row][col] = rand.randomFloat(-1, 1);
            minDistances[row][col] = rand.randomFloat(4, 25);
            maxInteractionDist[row][col] = rand.randomFloat(50, maxInteractionRange); // must be larger than minDistances
        }
    }
}

int World::getParticleCount() const {
    return particle_count;
}

const std::vector<Particle> &World::getParticles() const {
    return particles;
}

void World::update(double deltaTime) {
    // clear the grid before computing the next one
    for (int row = 0; row < gridHeight; row++) {
        for (int col = 0; col < gridWidth; col++) {
            gridCells[row][col].clear();
        }
    }

    // loop the particles vec and calculate the cell it belongs in, give that particles index to the gridCell
    for (int i = 0; i < particle_count; i++) {
        int row = std::clamp((int)particles[i].position.y / gridSize, 0, gridHeight - 1);
        int col = std::clamp((int)particles[i].position.x / gridSize, 0, gridWidth - 1);
        gridCells[row][col].push_back(i);
    }

    for (int i = 0; i < particle_count; i++) {
        Vec2 direction{};
        Vec2 totalForce{};
        Vec2 acceleration{};
        float distance;

        int row = std::clamp((int)particles[i].position.y / gridSize, 0, gridHeight - 1);
        int col = std::clamp((int)particles[i].position.x / gridSize, 0, gridWidth - 1);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (row + dx >= 0 && row + dx < gridHeight && col + dy >= 0 && col + dy < gridWidth) {
                    for (auto &j : gridCells[row + dx][col + dy]) {
                        if (i == j) continue;
                        direction = particles[j].position - particles[i].position;
                        distance = direction.mag();
                        direction.normalize();

                        if (distance < minDistances[particles[j].type][particles[i].type]) {
                            Vec2 force = direction;                                                 // the -5 scalar serves two purposes: flips the force direction to push particles away from each other,
                            force *= abs(forces[particles[j].type][particles[i].type]) * -5; // and makes the repulsion stronger than the attraction. If you change K or friction, the repulsion strength may need to be retuned to maintain that balance
                            force *= map(distance, 0, minDistances[particles[j].type][particles[i].type], 1, 0);
                            force *= 0.05; // scalar for force we will add later;
                            totalForce += force;
                        }

                        if (distance < maxInteractionDist[particles[j].type][particles[i].type]) {
                            Vec2 force = direction;
                            force *= forces[particles[j].type][particles[i].type];
                            force *= map(distance, 0, maxInteractionDist[particles[j].type][particles[i].type], 1, 0);
                            force *= 0.05; // K is a scalar for force we will add later;
                            totalForce += force;
                        }
                    }
                }
            }
        }

        acceleration += totalForce;
        particles[i].velocity += acceleration * deltaTime;
        particles[i].position += particles[i].velocity * deltaTime;
        particles[i].position.x = fmod(particles[i].position.x + world_width, world_width);
        particles[i].position.y = fmod(particles[i].position.y + world_height, world_height);
        particles[i].velocity *= 0.75; // friction
    }
}
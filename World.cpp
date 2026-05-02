#include "World.h"

void World::initWorld(int width, int height, int amount) {
    world_width = width;
    world_height = height;
    particle_count = amount;

    std::uniform_int_distribution<> randX(0, world_width);
    std::uniform_int_distribution<> randY(0, world_height);
    std::uniform_int_distribution<> rType(0, 4);

    for (int i = 0; i < particle_count; i++) {
        Particle p{512, 360};
        p.velocity += 0.1; // this could be used to give particles a small velocity at their spawn time
        p.type = rType(rng);
        particles.push_back(p);
    }

    // forces[numTypes][numTypes]{};
    // minDistances[numTypes][numTypes]{};
    // radii[numTypes][numTypes]{}; // must be bigger than minDistances

    std::uniform_real_distribution<float> fRand(-1, 1);
    std::uniform_real_distribution<float> mdRand(30, 50); // 30 50
    std::uniform_real_distribution<float> rRand(70, 250); // 70 250

    // TODO: Print tables for these matrices
    for (int row = 0; row < numTypes; row++) {
        for (int col = 0; col < numTypes; col++) {
            forces[row][col] = fRand(rng);
            minDistances[row][col] = mdRand(rng);
            radii[row][col] = rRand(rng);
        }
    }
}

int World::getParticleCount() const {
    return particle_count;
}

const std::vector<Particle> &World::getParticles() const {
    return particles;
}

void World::update() {
    for (int i = 0; i < particles.size(); i++) {
        Vec2 direction{};
        Vec2 totalForce{};
        Vec2 acceleration{};
        float distance;

        for (int j = 0; j < particles.size(); j++) {
            if (i == j) continue;
            direction = particles[j].position - particles[i].position;
            distance = direction.mag();
            direction.normalize();

            if (distance < minDistances[particles[j].type][particles[i].type]) {
                Vec2 force = direction;
                force *= abs(forces[particles[j].type][particles[i].type]) * -5; // -3 is a scalar subject to change
                force *= map(distance, 0, minDistances[particles[j].type][particles[i].type], 1, 0);
                force *= 0.05; // scalar for force we will add later;
                totalForce += force;
            }

            if (distance < radii[particles[j].type][particles[i].type]) {
                Vec2 force = direction;
                force *= forces[particles[j].type][particles[i].type];
                force *= map(distance, 0, radii[particles[j].type][particles[i].type], 1, 0);
                force *= 0.05; // K is a scalar for force we will add later;
                totalForce += force;
            }
        }

        acceleration += totalForce;
        particles[i].velocity += acceleration;
        particles[i].position += particles[i].velocity;
        particles[i].position.x = fmod(particles[i].position.x + world_width, world_width);
        particles[i].position.y = fmod(particles[i].position.y + world_height, world_height);
        particles[i].velocity *= 0.75; // friction
    }
}
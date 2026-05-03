#include "World.h"

void World::initWorld(int width, int height, int amount) {
    world_width = width;
    world_height = height;
    particle_count = amount;
    Randomizer rand;

    for (int i = 0; i < particle_count; i++) {
        Particle p{rand.randomFloat(500, 600), rand.randomFloat(300, 360)};
        p.velocity += 0;
        p.type = rand.randomInt(0, 7);
        particles.push_back(p);
    }

    // TODO: Print tables for these matrices
    for (int row = 0; row < numTypes; row++) {
        for (int col = 0; col < numTypes; col++) {
            forces[row][col] = rand.randomFloat(-1, 1);
            minDistances[row][col] = rand.randomFloat(4, 50);
            radii[row][col] = rand.randomFloat(70, 250); // must be larger than minDistances
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
        particles[i].velocity += acceleration * deltaTime;
        particles[i].position += particles[i].velocity * deltaTime;
        particles[i].position.x = fmod(particles[i].position.x + world_width, world_width);
        particles[i].position.y = fmod(particles[i].position.y + world_height, world_height);
        particles[i].velocity *= 0.75; // friction
    }
}
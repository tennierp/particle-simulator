#include "World.h"

void World::initializeParticles() {
    std::uniform_real_distribution<float> randX(0, world_width);
    std::uniform_real_distribution<float> randY(0, world_height);

    for (int i = 0; i < particle_count; i++) {
        Particle p{randX(rng), randY(rng)};
        particles.push_back(p);
    }

//    float forces[numTypes][numTypes]{};
//    float minDistances[numTypes][numTypes]{};
//    float radii[numTypes][numTypes]{}; // must be bigger than minDistances

    forces[0][0] = -1;
    minDistances[0][0] = 5;
    radii[0][0] = 100;
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
                force *= abs(forces[particles[j].type][particles[i].type] * -3); // -3 is a scalar subject to change
                force *= map(distance, 0, minDistances[particles[j].type][particles[i].type], 1, 0);
                force *= 0.1; // scalar for force we will add later;
                totalForce += force;
            }

            if (distance < radii[particles[j].type][particles[i].type]) {
                Vec2 force = direction;
                force *= forces[particles[j].type][particles[i].type]; // -3 in the if statement above is to create a strong repulsion if the particle is too close
                force *= map(distance, 0, radii[particles[j].type][particles[i].type], 1, 0);
                force *= 0.1; // K is a scalar for force we will add later;
                totalForce += force;
            }
        }

        acceleration += totalForce;
        particles[i].velocity += acceleration;
        particles[i].position += particles[i].velocity;
        particles[i].position.x = fmod(particles[i].position.x + world_width, world_width);
        particles[i].position.y = fmod(particles[i].position.y + world_height, world_height);
        particles[i].velocity *= 0.50; // friction
    }
}
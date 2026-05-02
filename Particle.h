#ifndef PARTICLE_SIMULATOR_PARTICLE_H
#define PARTICLE_SIMULATOR_PARTICLE_H
#include "Utils.h"

struct Particle {
    Vec2 position{}; // Position
    Vec2 velocity{};
    int type; // Particle type (color group)
};

#endif //PARTICLE_SIMULATOR_PARTICLE_H

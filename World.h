#ifndef PARTICLE_SIMULATOR_WORLD_H
#define PARTICLE_SIMULATOR_WORLD_H
#include "Particle.h"

class World {
    public:
        void initializeParticles();
        void create();

    private:
        Particle particles{};
};


#endif //PARTICLE_SIMULATOR_WORLD_H

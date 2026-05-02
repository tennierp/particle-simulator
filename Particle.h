#ifndef PARTICLE_SIMULATOR_PARTICLE_H
#define PARTICLE_SIMULATOR_PARTICLE_H
#include "Utils.h"
// TODO: Test particles having multiple trait-sets that switch randomly
/* Every particle carries a collection of inactive trait-sets, and a single
 * active trait-set, and they switch which is active periodically.
 * With high enough particle count, and seeding new particle types,
 * we get different emergent structures with high probability even
 * without waiting for evolution to take place. Without seeding new
 * types evolution does still take place though. Particle families
 * which stabilise each other for every trait set emerge
 * */

struct Particle {
    Vec2 position{};
    Vec2 velocity{};
    int type{};
};

#endif //PARTICLE_SIMULATOR_PARTICLE_H

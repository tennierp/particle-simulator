#ifndef PARTICLE_SIMULATOR_UTILS_H
#define PARTICLE_SIMULATOR_UTILS_H
#include <cmath>
#include <random>

struct Vec2 {
    float x, y;

    Vec2 operator+(const float n) const {
        return {x + n, y + n};
    }

    Vec2 operator+(const Vec2 &b) const {
        return {x + b.x, y + b.y};
    }

    Vec2 operator-(const float n) const {
        return {x - n, y - n};
    }

    Vec2 operator-(const Vec2 &b) const {
        return {x - b.x, y - b.y};
    }

    Vec2 operator*(const float n) const {
        return {x * n, y * n};
    }

    Vec2 operator*(const Vec2 &b) const {
        return {x * b.x, y * b.y};
    }
    Vec2 operator/(const float n) const {
        return {x / n, y / n};
    }

    Vec2 operator/(const Vec2 &b) const {
        return {x / b.x, y / b.y};
    }

    Vec2& operator+=(const float n) {
        this->x += n;
        this->y += n;
        return *this;
    }

    Vec2& operator+=(const Vec2 &b) {
        this->x += b.x;
        this->y += b.y;
        return *this;
    }

    Vec2& operator-=(const float n) {
        this->x -= n;
        this->y -= n;
        return *this;
    }

    Vec2& operator-=(const Vec2 &b) {
        this->x -= b.x;
        this->y -= b.y;
        return *this;
    }

    Vec2& operator*=(const float n) {
        this->x *= n;
        this->y *= n;
        return *this;
    }

    Vec2& operator*=(const Vec2 &b) {
        this->x *= b.x;
        this->y *= b.y;
        return *this;
    }

    Vec2& operator/=(const float n) {
        this->x /= n;
        this->y /= n;
        return *this;
    }

    Vec2& operator/=(const Vec2 &b) {
        this->x /= b.x;
        this->y /= b.y;
        return *this;
    }

    float mag() const {
        return std::sqrt(x * x + y * y);
    }

    void normalize() {
        float magnitude = this->mag();
        if (magnitude > 0) {
            this->x /= magnitude;
            this->y /= magnitude;
        }
    }
};

// take the distance, and map it from the range 0→minDistance onto the range 1→0
inline float map(float value, float inputMin, float inputMax, float outputMin, float outputMax) {
    if (inputMax - inputMin == 0) return outputMin;
    float fraction = (value - inputMin) / (inputMax - inputMin);
    return outputMin + fraction * (outputMax - outputMin);
}

struct Randomizer {
    std::mt19937 rng{std::random_device{}()};

    float randomFloat(float min, float max) {
        std::uniform_real_distribution<float> fRand(min,max);
        return fRand(rng);
    }

    int randomInt(int min, int max) {
        std::uniform_int_distribution<> intRand(min, max);
        return intRand(rng);
    }
};

#endif //PARTICLE_SIMULATOR_UTILS_H

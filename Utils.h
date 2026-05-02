#ifndef PARTICLE_SIMULATOR_UTILS_H
#define PARTICLE_SIMULATOR_UTILS_H
#include <cmath>

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
        this->x /= magnitude;
        this->y /= magnitude;
    }
};

#endif //PARTICLE_SIMULATOR_UTILS_H

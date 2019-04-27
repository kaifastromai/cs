#pragma once
#include "../include/rocket.h"
class MagnetRocket : public Rocket
{
public:
    MagnetRocket();
    MagnetRocket(Vector p, Vector v, float m = 1)
    {
        trigger_age = std::numeric_limits<int>::max();
        mass = m;
        velocity = v;
        momentum = v * m;
        age = 0;
        age_limit = 10;
        force = {0.0, 0.0};
        isTriggered = false;
        color_code = 5;
        position = p;
    };
    inline static const float d_t = 1;
    Vector momentum;
    Vector velocity;

    float mass; //It's like a gravitational orbit!
    void Step(std::deque<Rocket *> &d);
};
#pragma once
#include "../include/fiber_node.h"
class MagnetRocket : public FiberNode
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
        attraction_source = {0, 0};
    };
    void AttractToSource();
    inline static const float d_t = 1;
    Vector momentum;
    Vector velocity;
    Vector attraction_source;
    bool isSettled = false;

    float mass; //It's like a gravitational orbit!
    void Step(std::deque<MagnetRocket *> &d);
    void Step();
    void Draw()
    {
        Rocket::Draw();
    }
    bool isAtSource();
};
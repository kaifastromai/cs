#include "../include/magnet_rocket.h"
MagnetRocket::MagnetRocket()
{
    trigger_age = std::numeric_limits<int>::max();
    age = 0;
    age_limit = 5;
    position.x = COLS / 2;
    position.y = 0;
    force = {0.5, 2.0};
    isTriggered = false;
    color_code = 5;
    mass = 0;
    velocity = {0, 0};
    force = {0, 0};
    momentum = velocity * mass;
};
void MagnetRocket::Step(std::deque<Rocket *> &d)
{
    if (age == trigger_age)
    {
        Trigger(d);
    }
    age++;
    momentum += force * d_t;
    velocity = momentum / mass;
    position += velocity * d_t;
}
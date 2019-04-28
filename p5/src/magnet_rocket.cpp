#include "../include/magnet_rocket.h"
#include "../include/util.storm.h"
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
    attraction_source = {COLS / 2, LINES / 2};
};
void MagnetRocket::Step(std::deque<MagnetRocket *> &d)
{
    if (age == trigger_age)
    {
        // Trigger(d);
    }
    age++;
    momentum += force * d_t;
    velocity = momentum / mass;
    position += velocity * d_t;
}
void MagnetRocket::Step()
{
    age++;
    momentum += force * d_t;
    velocity = momentum / mass;
    position += velocity * d_t;
}
void MagnetRocket::AttractToSource()
{
    if ((int)position.x == (int)attraction_source.x && (int)position.y == (int)attraction_source.y)
    {
        if ((int)velocity.x == 0 && (int)velocity.y == 0)
        {
            this->velocity = {0, 0};
            this->momentum = {0, 0};
            this->position = attraction_source;
            this->isSettled = true;
        }
    }

    else
    {
        csl::utils::physics::attract_to_location_spring(attraction_source, this, 0.1, 0, 0.5);
    }
}

bool MagnetRocket::isAtSource()
{
    return ((int)position.x == (int)attraction_source.x && (int)position.y == (int)attraction_source.y);
}

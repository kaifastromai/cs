
#pragma once
#include <iostream>
#include <vector>
#include "../include/fiber_node.h"
#include <curses.h>
#include "../include/rocket.h"
#include <deque>
#include "../include/sparkler.h"
class Grid : public Rocket
{

public:
    Grid(int dimx = 4, int dimy = 4, int seperation = 0);
    ~Grid();
    void AttractToGrid(std::deque<Rocket *> rs);
    void DrawFlag();
    void DrawCircle(std::deque<Rocket *> &d, int r, Vector ref_pos);
    struct
    {

        int dimx;
        int dimy;
    } dimensions;

protected:
    std::vector<std::vector<FiberNode *>> grid;

public:
    void  Draw(std::deque<Rocket *> &v);
    void Trigger(std::deque<Rocket *> &v);
    void Simulate(int &phase, float speed = 3, float magnitude = 4);
};

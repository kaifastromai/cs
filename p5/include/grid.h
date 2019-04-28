
#pragma once
#include <iostream>
#include <vector>
#include "../include/fiber_node.h"
#include <curses.h>
#include "../include/rocket.h"
#include <deque>
#include "../include/magnet_rocket.h"
class Grid : public Rocket
{

public:
    Grid(int dimx = 4, int dimy = 4, int seperation = 0);
    ~Grid();
    void AttractToGrid(std::deque<Rocket *> rs);
    void DrawFlag();
    void DrawFlagFromParticles();

    void DrawCircle(int r, Vector ref_pos);
    void SetAttractSources();
    void DB_DrawSources(std::deque<Rocket *> &rs);
    //static std::vector<Vector> rckt_climax;
    void DrawCircleOnFrame(int r, Vector ref_pos, std::deque<Rocket *> &rckts);
    void SimulateMagnets();
    struct
    {

        int dimx;
        int dimy;
    } dimensions;

protected:
    std::vector<std::vector<FiberNode *>> grid;
    std::deque<MagnetRocket *> mrs;

public:
    void Draw(std::deque<Rocket *> &v);
    void Trigger(std::deque<Rocket *> &v);
    void Simulate(int &phase, float speed = 1, float magnitude = 4);
    bool HasSettled();
};

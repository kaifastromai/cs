#include <iostream>
#include "../include/rocket.h"
#include <curses.h>
#include "../include/vector.h"
#include <vector>
class FiberNode
{
public:
    float k;
    float stretch;
    float L0;
    Vector pos;
    //methods
public:
    FiberNode();
    FiberNode(float posx = 0, float posy = 0)
    {
        this->pos.x = posx;
        this->pos.y = posy;
    }
    void Draw()
    {
        mvaddch(pos.y, pos.x, '*');
    }

public:
    Vector index;
    void Simulate();
};
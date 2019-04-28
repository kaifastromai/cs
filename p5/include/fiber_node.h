#pragma once
#include <iostream>
#include <curses.h>
#include "../include/vector.h"
#include <vector>
#include "../include/rocket.h"
#include <memory.h>
class FiberNode : public Rocket
{
public:
    Vector pos;
    //methods
public:
    FiberNode(Vector pos)
    {
        this->position = pos;
    }
    void Draw()
    {
        mvaddch(pos.y, pos.x, '*');
        pos.x = COLS / 2 + index.x - (COLS / 3) / 2;
        pos.y = LINES / 2 - index.y + (LINES / 3) / 2;
    }
    void Step();

public:
    Vector index;
};
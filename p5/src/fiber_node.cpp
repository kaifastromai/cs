#include "../include/fiber_node.h"
void FiberNode::Step()
{
    age++;
    pos.y += force.y;
    pos.x += force.x;
    //force.y -= gravity;
}
#include "../include/fiber_node.h"
void FiberNode::Step()
{
    age++;
    position.y += force.y;
    position.x += force.x;
    //force.y -= gravity;
    
}
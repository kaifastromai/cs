
#include <iostream>
#include <vector>
#include "../include/fiber_node.h"
#include <curses.h>
#include "../include/rocket.h"
class Grid
{

public:
    Grid(float dimx = 4, float dimy = 4, int seperation = 0)
    {
        int iny = 0;

        for (int i = 0; i <= (seperation + 1) * dimy; i += (seperation + 1))
        {
            int inx = 0;
            std::vector<FiberNode *> v;

            for (int j = 0; j <= (seperation + 1) * dimx; j += (seperation + 1))
            {

                FiberNode *fbr = new FiberNode(LINES - i - dimy, COLS + j - dimx);
                fbr->index.x = inx;
                fbr->index.y = iny;
                inx++;
                v.push_back(fbr);
            }
            iny++;

            grid.push_back(v);
        }
    }
    ~Grid()
    {
    }
    std::vector<std::vector<FiberNode *>> grid;

    struct
    {

        int dimx;
        int dimy;
    } dimensions;

protected:
public:
    void Draw()
    {

        for (auto vec_in_grid : grid)
        {
            for (auto node_in_vec : vec_in_grid)
            {
                float y = node_in_vec->index.x;
                int mody = fmod(y, 2);

                if (mody == 0)
                {

                    Rocket::Log(mody);
                    attron(COLOR_PAIR(5));
                }
                else if (mody == 1)
                {

                    attron(COLOR_PAIR(1));
                }

                if (node_in_vec->index.x >= 8 && node_in_vec->index.y >= 5)
                {
                    attron(COLOR_PAIR(3));
                }

                node_in_vec->Draw();
            }
        }
    }
};
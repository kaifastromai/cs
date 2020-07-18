#include "../include/grid.h"
#include "../include/util.storm.h"
#define TAU (M_PI * 2)

Grid::Grid(int dimx, int dimy, int seperation)
{

    trigger_age = std::numeric_limits<int>::max();
    age = 0;
    age_limit = 5;
    position.x = COLS / 2;
    position.y = 0;
    force = {0.5, 2.0};
    isTriggered = false;
    color_code = 5;
    int iny = 0;

    for (int i = 0; i <= (seperation + 1) * dimy; i += (seperation + 1))
    {
        int inx = 0;
        std::vector<FiberNode *> v;

        for (int j = 0; j <= (seperation + 1) * dimx; j += (seperation + 1))
        {
            int l_posy = LINES / 2 - i + dimy / 2;
            int l_posx = COLS / 2 + j - dimx / 2;
            FiberNode *fbr = new FiberNode(l_posx, l_posy);
            fbr->index.x = inx;
            fbr->index.y = iny;
            inx++;
            v.push_back(fbr);
        }
        iny++;

        grid.push_back(v);
    }
    this->dimensions = {dimx, dimy};
}
Grid::~Grid()
{
}
void Grid::Draw(std::deque<Rocket *> &v)
{
    Vector force(0, 3);
    for (int i = 0; i < 3; i++)
    {
        Rocket *r = new Rocket();
        r->SetForce(1 - i, 5);
        r->SetPosition(COLS / 2 - 4 + 8 * i, 0);
        r->SetAgeLimit(5 / 0.2);
        v.push_back(r);
    }
}
void Grid::Simulate(int &phase, float speed, float magnitude)
{

    float angle = 1.0f / (float)dimensions.dimx;
    for (auto vec_in_grid : grid)
    {
        int i = 0;
        for (auto node_in_vec : vec_in_grid)
        {
            float ang = std::cos((2.0f * M_PI * speed * angle) * (float)i - phase);
            node_in_vec->pos.y += std::round(magnitude * ang) - std::round((i / 16) * std::sin(phase));
            i++;
            node_in_vec->Step();
        }
    }
}
void Grid::Trigger(std::deque<Rocket *> &v)
{
    std::deque<Rocket *> lcl_rockets = v;
    for (auto lcl_rckt : lcl_rockets)
    {
        int r = (LINES / 6) * (COLS / 6) / 3;
        Vector vec(lcl_rckt->position.x, lcl_rckt->position.y);
        DrawCircle(v, r, vec);
    }
}
void Grid::AttractToGrid(std::deque<Rocket *> rs)
{
}
void Grid::DrawFlag()
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
void Grid::DrawCircle(std::deque<Rocket *> &d, int r, Vector ref_pos)
{
    for (int i = 1; i <= r; i++)
    {
        //*log << i << std::endl;
        //*log << "Coords: " << x << ", " << y << std::endl;
        //*Rocket::log << "Force x: " << r.force.x << ", " << r.force.y << std::endl;
        //*log << "Pos: x" << r.position.x << ", y:" << r.position.y << std::endl;
        //mvaddch(LINES - i, i, '*');
        float posx = (float)cos(TAU * (1.0f / (float)r) * i) + ref_pos.x;
        float posy = (float)sin(TAU * (1.0f / (float)r) * i) + ref_pos.y;
        float fx = 4 * (float)cos(TAU * (1.0f / (float)r) * i);
        float fy = 4 * (float)sin(TAU * (1.0f / (float)r) * i);
        /* float posx = this->position.x+i;
		float posy = this->position.y+i; */
        Sparkler *spk = new Sparkler();
        spk->SetColor(1);
        spk->SetAgeLimit(csl::utils::Jiggle(20, 40));
        spk->SetPosition(posx, posy);
        /* r->SetForce(1.0f / (1.0f * (float)sin(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f),
					-1.0f / (1.0f * (float)cos(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f)); */
        spk->SetForce(fx, fy);
        d.push_back(spk);
    }
}

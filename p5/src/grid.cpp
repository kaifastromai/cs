#include "../include/grid.h"
#include "../include/util.storm.h"
#include "../include/streamer.h"
#include <thread>
#include <future>

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

    for (int i = 0; i < (seperation + 1) * dimy; i += (seperation + 1))
    {
        int inx = 1;
        std::vector<FiberNode *> v;

        for (int j = 0; j < (seperation + 1) * dimx; j += (seperation + 1))
        {
            int l_posy = LINES / 2 - i + dimy / 2;
            int l_posx = COLS / 2 + j - dimx / 2;
            FiberNode *fbr = new FiberNode(Vector(l_posx, l_posy));
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
        r->SetForce(3 - 3 * i, 5);
        r->SetPosition(COLS / 2 - 4 + 8 * i, 0);
        r->SetAgeLimit(5 / 0.2);
        v.push_back(r);
    }
}
void Grid::Simulate(int &phase, float speed, float magnitude)
{

    if (age > trigger_age)
    {
        if (age == trigger_age + 1)
        {
            SetAttractSources();
        }
        Rocket::Log(HasSettled());
        DrawFlagFromParticles();
        int j = 0;
        float angle = 1.0f / (float)dimensions.dimx;
        for (auto vec_in_grid : grid)
        {
            int i = 0;
            for (auto node_in_vec : vec_in_grid)
            {
                float ang = std::cos((2.0f * M_PI * speed * angle) * (float)i - phase);
                float n_y = std::round(magnitude * ang) - std::round((i / 16) * std::sin(phase));
                node_in_vec->position.y += n_y;
                if (age > 100)
                {
                    mrs.at(j)->position = node_in_vec->position;
                }
                //
                //Rocket::Log(mrs.at(j)->isSett);
                i++;
                node_in_vec->Step();
                node_in_vec->Draw();
                j++;
            }
        }
    }
}
void Grid::Trigger(std::deque<Rocket *> &v)
{
    int r = (LINES / 3) * (COLS / 3);
    std::deque<Rocket *> lcl_rckts;
    int i = 0;
    for (auto lcl_rckt : v)
    {
        DoubleStreamer *t_s = new DoubleStreamer();
        t_s->SetPosition(lcl_rckt->position.x, lcl_rckt->position.y);
        t_s->SetForce(5 - 5 * i, 3);
        t_s->SetTriggerAge(10);
        t_s->SetColor(2);
        t_s->force_coef = 2;
        lcl_rckts.push_back(t_s);
        DrawCircle(r, Vector(lcl_rckt->position.x, lcl_rckt->position.y));
        i++;
    }

    v.insert(v.begin(), lcl_rckts.begin(), lcl_rckts.end());
}
void Grid::DrawFlag()
{
    //std::thread
    if (HasSettled())
    {
        for (auto vec_in_grid : grid)
        {
            for (auto node_in_vec : vec_in_grid)
            {
                float y = node_in_vec->index.x;
                int mody = fmod(y, 2);

                if (mody == 0)
                {

                    //Rocket::Log(mody);
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
            }
        }
    }
}
void Grid::DrawFlagFromParticles()
{
    //std::thread

    for (auto mr : mrs)
    {
        float y = mr->index.x;
        int mody = fmod(y, 2);

        if (mody == 0)
        {

            //Rocket::Log(mody);
            //attron(COLOR_PAIR(5));
            mr->SetColor(5);
        }
        else if (mody == 1)
        {

            mr->SetColor(1);
        }

        if (mr->index.x >= 8 && mr->index.y >= 5)
        {
            // attron(COLOR_PAIR(3));
            mr->SetColor(3);
        }

        mr->Draw();
        mr->Step();

        /*   mr->position.x = COLS / 2 + mr->index.x - (COLS / 3) / 2;
        mr->position.y = LINES / 2 - mr->index.y + (LINES / 3) / 2; */
    }
}
void Grid::DrawCircle(int r, Vector ref_pos)
{
    r /= 3;
    for (int i = 0; i <= r; i++)
    {
        float force_coef = csl::utils::Jiggle<float>(40, 34);

        //*log << i << std::endl;
        //*log << "Coords: " << x << ", " << y << std::endl;
        //*Rocket::log << "Force x: " << r.force.x << ", " << r.force.y << std::endl;
        //*log << "Pos: x" << r.position.x << ", y:" << r.position.y << std::endl;
        //mvaddch(LINES - i, i, '*');
        Vector pos = {(float)cos(TAU * (1.0f / (float)r / 3) * i) + ref_pos.x,
                      (float)sin(TAU * (1.0f / (float)r) * i) + ref_pos.y};
        /* float posx = (float)cos(TAU * (1.0f / (float)r) * i) + ref_pos.x;
        float posy = (float)sin(TAU * (1.0f / (float)r) * i) + ref_pos.y; */
        Vector fv = {force_coef * (float)cos(TAU * (1.0f / (float)r) * i),
                     force_coef * (float)sin(TAU * (1.0f / (float)r) * i)};
        /* float fx = 4 * (float)cos(TAU * (1.0f / (float)r) * i);
        float fy = 4 * (float)sin(TAU * (1.0f / (float)r) * i); */
        /* float posx = this->position.x+i;
		float posy = this->position.y+i; */
        MagnetRocket *mr = new MagnetRocket(pos, fv);
        mr->SetColor(1);
        mr->SetAgeLimit(csl::utils::Jiggle(20, 40));
        /* r->SetForce(1.0f / (1.0f * (float)sin(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f),
					-1.0f / (1.0f * (float)cos(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f)); */
        mrs.push_back(mr);
    }
}
void Grid::DrawCircleOnFrame(int r, Vector ref_pos, std::deque<Rocket *> &rckts)
{
    if (age >= trigger_age && age <= (age + r / 18))
    {

        r /= 3;
        int part = MagnetRocket::frame % (r / 6);
        //*log << i << std::endl;
        //*log << "Coords: " << x << ", " << y << std::endl;
        //*Rocket::log << "Force x: " << r.force.x << ", " << r.force.y << std::endl;
        //*log << "Pos: x" << r.position.x << ", y:" << r.position.y << std::endl;
        //mvaddch(LINES - i, i, '*');
        for (int i = 0; i <= std::lround(r / 6); i++)
        {
            Vector pos = {(float)cos(TAU * (1.0f / (float)r / 3) * part) + ref_pos.x,
                          (float)sin(TAU * (1.0f / (float)r) * part) + ref_pos.y};
            /* float posx = (float)cos(TAU * (1.0f / (float)r) * i) + ref_pos.x;
        float posy = (float)sin(TAU * (1.0f / (float)r) * i) + ref_pos.y; */
            Vector fv = {4 * (float)cos(TAU * (1.0f / (float)r) * part),
                         4 * (float)sin(TAU * (1.0f / (float)r) * part)};
            /* float fx = 4 * (float)cos(TAU * (1.0f / (float)r) * i);
        float fy = 4 * (float)sin(TAU * (1.0f / (float)r) * i); */
            /* float posx = this->position.x+i;
		float posy = this->position.y+i; */
            MagnetRocket *mr = new MagnetRocket(pos, fv);
            mr->SetColor(1);
            mr->SetAgeLimit(csl::utils::Jiggle(20, 40));
            /* r->SetForce(1.0f / (1.0f * (float)sin(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f),
					-1.0f / (1.0f * (float)cos(TAU * (1.0f / 16.0f) * i * 4) + 0.0001f)); */
            mrs.push_back(mr);
            rckts.push_back(mr);
        }
    }
}
void Grid::SimulateMagnets()
{
    if (age >= trigger_age)
    {
        for (auto mr : mrs)
        {
            mr->AttractToSource();
        }
    }
}
//Must be called after mrs has been initiliazed!
void Grid::SetAttractSources()
{
    int i = 0;

    for (auto rows : grid)
    {
        for (auto cols : rows)
        {

            mrs.at(i)->attraction_source = cols->position;
            mrs.at(i)->index = cols->index;
            i++;
        }
    }
    Rocket::Log(__LINE__, " ", i);
}
void Grid::DB_DrawSources(std::deque<Rocket *> &rs)
{
    //std::deque<Rocket *> lcl_rckts;
    if (IS_DEBUG_MODE && age == (trigger_age + 1))
    {
        for (auto mr : mrs)
        {
            rs.push_back(new MagnetRocket(mr->attraction_source, Vector(0, 0)));
        }
    }
}
bool Grid::HasSettled()
{
    int settled = 0;
    int unsettled = 0;
    if (age > trigger_age)
    {
        for (auto mr : mrs)
        {
            if (!mr->isSettled)
            {
                unsettled++;
            }
            else
            {
                settled++;
            }
        }
        return settled > unsettled + settled * 0.9;
    }
    return false;
}

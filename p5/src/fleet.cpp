#include "../include/fleet.h"
#include "../include/util.storm.h"
#include <cmath>

void Fleet::Run(float chance_at_birth, float initial_up_force)
{
    try
    {
        if (utils::weighted_bool(chance_at_birth))
        {
            Birth(initial_up_force);
        }
        Cull();
        Step();
        Draw();
    }
    catch (std::exception &e)
    {
        *Rocket::log << e.what() << std::endl;
        std::abort();
    }
}
void Fleet::Cull()
{
    for (auto rocket : rockets)
    {
        if ((rocket) != nullptr)
        {
            if (!rocket->IsAlive())
            {
                auto item = std::find(rockets.begin(), rockets.end(), rocket);
                if (item != rockets.end())
                {
                     delete *item;
                    rockets.erase(item);
                }
            }
        }
        else
        {
            throw std::runtime_error("pointer is invalid");
        }
    }
}

void Fleet::Birth(float initial_up_force)
{

    rockets.push_back(RocketFactory(initial_up_force));
}
void Fleet::Step()
{
    std::vector<Rocket *> lcl_rockets;
    for (Rocket *rocket : rockets)
    {

        rocket->Step(lcl_rockets);
    }
    if (!lcl_rockets.empty())
    {
        rockets.insert(rockets.begin(), lcl_rockets.begin(), lcl_rockets.end());
    }
}

void Fleet::Draw()
{
    if (!rockets.empty())
    {
        for (auto rocket : rockets)
        {
            rocket->Draw();
        }
    }
    else
    {
        Rocket::Log("There are no rockets yet..");
    }
}
Rocket *Fleet::RocketFactory(float initial_up_force)
{
    Rocket_Type type = Rocket_Type(utils::unif<int>(0, 3));

    switch (type)
    {
    case IE_Rocket:
    {
        //*Rocket::log << "normals rockets" << std::endl;
        Rocket *r = new Rocket();
        r->SetForce(utils::Jiggle(0.4, 30), initial_up_force);
        r->SetAgeLimit(utils::Jiggle<float>((2 * std::get<1>(r->GetForce()) / -g), 25));
        r->SetPosition(utils::Jiggle<float>(COLS / 2, 50), 0);
        return r;
        break;
    }
    case IE_Palm_Tree:
    {
        // *Rocket::log << "palm Tree" << std::endl;
        PalmTree *p = new PalmTree();
        p->SetColor(3);
        p->SetForce(utils::unif<int>(-1, 1) * utils::Jiggle<float>(1, 50), utils::Jiggle<int>(initial_up_force, 50));
        auto forcev = p->GetForce();
        p->SetAgeLimit(((std::get<1>(forcev)) / -g));
        p->SetPosition(utils::Jiggle<int>(COLS / 2, 100), 0);
        p->SetTriggerAge((std::get<1>(forcev)) / 0.2);
        // p->SetTriggerAge(utils::Jiggle<int>(20, 40));
        return p;
        break;
    }
    case IE_Streamer:
    {
        //*Rocket::log << "streamer" << std::endl;
        Streamer *s = new Streamer();
        s->SetForce(utils::unif<int>(-1, 1) * utils::Jiggle<float>(1, 50), utils::Jiggle<int>(initial_up_force, 50));
        auto forcev = s->GetForce();
        s->SetAgeLimit((std::get<1>(forcev)) / 0.2f);
        s->SetPosition(utils::Jiggle<int>(COLS / 2, 100), 0);
        s->SetTriggerAge((std::get<1>(forcev)) / 0.2f);
        return s;
        break;
    }
    case IE_DoubleStreamer:
    {

        DoubleStreamer *ds = new DoubleStreamer();
        ds->SetForce(utils::unif<int>(-1, 1) * utils::Jiggle<float>(1, 50), utils::Jiggle<int>(initial_up_force, 50));
        auto forcev = ds->GetForce();
        ds->SetAgeLimit((std::get<1>(forcev)) / 0.2f);
        ds->SetPosition(utils::Jiggle<int>(COLS / 2, 100), 0);
        ds->SetTriggerAge((std::get<1>(forcev)) / 0.2f);
        return ds;
        break;
    }
    default:
        Rocket *r = new Rocket();
        return r;
        break;
    }
}
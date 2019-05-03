#include "../include/finale.h"
Finale::Finale()
{
    grid = new Grid(COLS / 3, LINES / 3);

    grid->SetTriggerAge(20);
    grid->SetAgeLimit(2000);
    grid->SetForce(0, 3);
    grid->Draw(rockets);
}
void Finale::Run()
{
    for (auto rckt : rockets)
    {
        rckt->Step(rockets);
        rckt->Draw();
    }
    grid->Step(rockets);
    grid->SimulateMagnets();
    // grid->SetAttractSources();
    // grid->DB_DrawSources(rockets);
    grid->Simulate(Rocket::frame, 1, 3);
    //Rocket::Log(rockets.size());
    grid->DrawFlag();
    // grid->DrawFlagFromParticles();
    //Rocket::Log(grid->HasSettled());
}
void Finale::Step()
{
}

Finale::~Finale()
{
}
void Finale::Cull()
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
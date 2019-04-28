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
        rckt->Step();
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
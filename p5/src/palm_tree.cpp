#include "../include/palm_tree.h"
void PalmTree::Trigger(std::vector<Rocket *> &v)
{
    Log("I have been triggered!");
    for (size_t i = 1; i <= 8; i++)
    {
        float posx = position.x;
        float posy = position.y;
        Sparkler *spk = new Sparkler();
        spk->SetColor(4);
        spk->SetAgeLimit(utils::Jiggle(20, 40));
        spk->SetPosition(posx, posy);
        auto forcev = GetForce();
        spk->SetForce(std::get<1>(forcev), std::get<0>(forcev));
        v.push_back(spk);
    }
}
PalmTree::~PalmTree()
{
}
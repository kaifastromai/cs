#include "../include/palm_tree.h"
#include "../include/util.storm.h"
void PalmTree::Trigger(std::deque<Rocket *> &v)
{
    Log("I have been triggered!");
    for (size_t i = 0; i <= 8; i++)
    {
        float posx = position.x;
        float posy = position.y;
        Sparkler *spk = new Sparkler();
        spk->SetColor(3);
        spk->SetAgeLimit(csl::utils::Jiggle<int>(300, 40));
        spk->SetPosition(posx, posy);
        auto forcev = GetForce();
        float cof = (4.0f - (float)i) / 4.0f;
        spk->SetForce(1.2 * cof * (std::get<0>(forcev) + 2), std::get<1>(forcev));
        v.push_back(spk);
    }
}
PalmTree::~PalmTree()
{
}
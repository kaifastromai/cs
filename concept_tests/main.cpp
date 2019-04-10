#include <iostream>
using namespace std;
class Mammal
{
  public:
    void Speak();
};
void Mammal::Speak()
{
    cout << "Generic mammal sound" << endl;
}
class Feline : public Mammal
{
  public:
    void Speak()
    {
        cout << "Mew" << endl;
    }
};

int main()
{
    Mammal m;
    Feline f;
    m.Speak();
    f.Speak();
};
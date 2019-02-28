#include <string>
#include <map>
#include <random>
#include <ctime>
#include <utility>
#include <iostream>
using namespace std;
class n
{
  public:
    int init;
    n(){};
};

int main()
{
    map<n *, string> mp;
    string s;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 10; i++)
    {
        int t = rand();
        mp.emplace(new n, to_string(t));
    }
    /*  for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        //cout << it->first << " " << it->second << endl;
    } */

    int input = 0;
    /*  while (input >= 0)
    {
        cout << "enter a number to look for: " << endl;
        cin >> input;
        if (input < 0)
            break;
        if (mp.count(input) > 0)
        {
            cout << "found it" << endl;
        }
    } */
}
#include <string>
#include <map>
#include <random>
#include <ctime>
#include <utility>
#include <iostream>
using namespace std;
class Node
{
  public:
    bool operator<(const Node &otherInstance) const;
    int init;
    Node();
};

int main()
{
    map<Node, string> mp;
    string s;
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 10; i++)
    {

        int t = rand();
        Node n;
        pair<string, Node> p = make_pair("hello", n);
        mp.emplace(p);
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

bool Node::operator<(const Node &otherInstance) const
{
    if (init > otherInstance.init)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node::Node()
{
}

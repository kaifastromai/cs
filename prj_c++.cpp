// prj_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class list_helper
{
  public:
	friend class std::list<int>;
	int sum_list(std::list<int> *l)
	{
		int sum = 0;

		for (int i : *l)
		{
			sum += i;
		}

		return sum;
	}
};
int main(int argc, char *argv[])
{
	list_helper ls;
	list<list<int> *> outer_list;
	ifstream inp;
	int listCounter = 0;

	if (argc > 1)
	{
		inp.open(argv[1]);
		if (inp.is_open())
		{
			for (string line; getline(inp, line);)
			{
				if (!line.empty())
				{
					list<int> *l_tmp = new list<int>;
					listCounter++;
					for (int i = 0; i < line.size(); i++)
					{
						if (line[i] != ' ')
						{

							l_tmp->push_back(atoi(&line[i]));
						}
					}
					outer_list.push_back(l_tmp);
				}
			}
		}
		else
		{
			cout << "Unable to open " << argv[1] << endl;
			return 1;
		}
	}
	else
	{
		cout << "Must provide name of input file." << endl;
		return 1;
	}
	cout << "List Counter: " << listCounter << endl;
	cout << "Size of outer list: " << outer_list.size() << endl;
	int list_index = 1;
	for (list<int> *l : outer_list)
	{
		cout << "List " << list_index << " has " << l->size() << " elements"
			 << " and sums to " << ls.sum_list(l) << endl;
		list_index++;
		//deallocate outer_list
		delete l;
	}
	inp.close();
	return 0;
}

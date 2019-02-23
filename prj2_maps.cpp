// prj_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//parses a file by spliting on all punctuation/spaces/tabs/endlines and then sends to a txt doc line by line.
string parse_file_to_txt(string filename)
{
	ifstream inp;
	ofstream onp;
	onp.open("output.txt");
	inp.open(filename);
	if (inp.is_open())
	{
		for (string line; getline(inp, line);)
		{
			if (!line.empty())
			{
				for (string::iterator i = line.begin(); i <= line.end() - 1; i++)
				{
					if (!ispunct(line.at(*i)) && !ispunct(line.at(*i + 1)))
					{
						onp << line.at(*i);
					}
					onp << endl;
				}
			}
		}
	}
	else
	{
		cout << "Error reading file" << endl;
	}

	onp.close();
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		parse_file_to_txt(argv[2]);
	}

	else
	{
		cout << "Must provide name of input file." << endl;
		return 1;
	}

	return 0;
}
//namespace std;

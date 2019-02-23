// prj_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//parses a file by spliting on all punctuation/spaces/tabs/endlines and then sends to a txt doc line by line.
void parse_file_to_txt(string filename)
{
	ifstream inp;
	ofstream onp;
	onp.open("output.txt");
	inp.open(filename);
	if (inp.is_open() && onp.is_open())
	{
		cout << "Files are opened!" << endl;
		for (string line; getline(inp, line);)
		{
			if (!line.empty())
			{
				cout << "Line is not empty!" << endl;
				string word;
				for (stringstream ss; ss >> word;)
				{
					cout << "The string is: " << ss.str() << endl;
					stringstream s;

					for (char c : word)
					{
						s << c;
					}
					onp << "Hello from the other side" << endl;
				}
			}
			else
			{
				cout << "Line is empty!" << endl;
			}
		}
		return onp.close();
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
		parse_file_to_txt(argv[1]);
		cout << "entered main" << endl;
	}

	else
	{
		cout << "Must provide name of input file." << endl;
		return 1;
	}

	return 0;
}
//namespace std;

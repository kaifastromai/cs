// prj_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
using namespace std;

//parses a file by spliting on all punctuation/spaces/tabs/endlines and then sends to a txt doc line by line.
class Node
{
  public:
	Node()
	{
		frequency = 1;
	}
	int frequency;
	vector<int> appears_on_lines;
};
vector<string> parse_file_to_txt(string filename)
{
	vector<string> strvec;
	ifstream inp;
	ofstream onp;
	onp.open("output.txt");
	inp.open(filename);
	if (inp.is_open() && onp.is_open())
	{
		//cout << "Files are opened!" << endl;
		for (string line; getline(inp, line);)
		{
			if (!(line.empty() == true || line == "\0"))
			{
				string word;
				stringstream ss(line);

				for (ss; ss >> word;)
				{
					if (!ss.str().empty())
					{
						//cout << "The string is: "<<ss.str() << endl;
						stringstream s;
						string::iterator it = word.begin();

						while (it != word.end())
						{
							if ((it) != word.begin() && (it + 1) != word.end() && ispunct(*it) && !ispunct(*(it + 1)))
							{
								s << *it;
							}
							else if (isalpha(*it) || isdigit(*it))
							{
								s << *it;
							}

							it++;
						}
						strvec.push_back(s.str());
					}
					else
					{
						cout << "word is empty" << endl;
					}
				}
			}
			else
			{
				//cout << "Line is empty!" << endl;
			}
		}
		for (string s : strvec)
		{
			//cout << "adding to string" << endl;
			if (!s.empty())
			{
				onp << s;
				onp << endl;
			}
		}
		return strvec;
		onp.close();
	}
	else
	{
		cout << "Could not open: " << filename << endl;
	}

	onp.close();
}

int main(int argc, char *argv[])
{
	map<string, Node> words;
	if (argc > 1)
	{
		parse_file_to_txt(argv[1]);
	}

	else
	{
		cout << "Must provide name of input file." << endl;

		return 1;
	}

	return 0;
}
//namespace std;

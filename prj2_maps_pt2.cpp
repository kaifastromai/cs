#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
#include "./storm_lib.h"
using namespace std;
class Node
{
  private:
    std::stringstream s;

  public:
    string str;
    bool is_majorCase;

    Node()
    {
        frequency = 1;
        str = "hello";
    }
    int frequency;
    vector<int> appears_on_lines;
    operator string()
    {
        s << str << " "
          << "found " << ((frequency == 1) ? "once on line:" : to_string(frequency) + " times on lines:") << endl;
        int i = 0;
        for (auto item : appears_on_lines)
        {
            if (i != appears_on_lines.size() - 1)
            {
                s << item << ","
                  << " ";
                i++;
            }
            else
            {
                s << item;
            }
        }
        return s.str();
    }
};

vector<string> readfile(string filename)
{
    vector<string> invec;
    ifstream inp(filename);
    if (inp.is_open())
    {
        for (string line; getline(inp, line);)
        {
            invec.push_back(line);
        }
    }
    inp.close();
    return invec;
}

int main(int argc, char *argv[])
{
    map<string, Node *> words;
    if (argc > 1)
    {
        if (argc < 2)
        {

            bool is_case_sensitive = true;
            if (storm_lib::trim((string)argv[2]) == "-case-sensitive" || storm_lib::trim((string)argv[2]) == "-cs")
            {
                cout << "Case sensitive mode activated!" << endl;
                is_case_sensitive = true;
            }
            if (storm_lib::trim((string)argv[2]) == "-not-sensitive" || storm_lib::trim((string)argv[2]) == "-ns")
            {
                is_case_sensitive = false;
            }
            int i = 1;
            for (string s : readfile(argv[1]))
            {

                storm_lib::rtrim(s);
                Node *n = new Node();
                if (is_case_sensitive)
                {
                    n->is_majorCase = isupper(s[0]);
                }
                else
                {
                    for (char c : s)
                    {
                        tolower(c);
                    }
                }
                n->appears_on_lines.push_back(i);
                n->str = s;
                auto p = words.insert(make_pair(s, n));
                if (!p.second)
                {
                    p.first->second->frequency++;
                    p.first->second->appears_on_lines.push_back(i);
                    //cout << "We found multiples of: " << p.first->second->str << endl;
                }
                i++;
            }
            string instr;
            while (!(instr[0] == 'q'))
            {

                cout << "Enter a word (case sensitive): ";
                string s;
                cin >> s;
                instr = s;
                trim(instr);
                if (!isalpha(instr[0]) && !isdigit(instr[0]))
                {
                    break;
                }
                cout << instr << endl;
                if (is_case_sensitive)
                {
                    for (char c : instr)
                    {
                        tolower(c);
                    }
                }

                if (words.find(instr) != words.end())
                {
                    auto it = words.find(instr);
                    cout << (string)(*(it->second)) << endl;
                }
                else
                {
                    cout << "Could not locate: " << instr << endl;
                }
            }
        }
    }

    else
    {
        cout << "Must provide name of input file." << endl;

        return 1;
    }

    return 0;
}
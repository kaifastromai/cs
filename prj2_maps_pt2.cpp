#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "./storm_lib.h"
#include <climits>
#include <stdio.h>
#include <unistd>
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
    //Overload cast to std::string()
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
//File words stored in vector so we can clean it up later
pair<vector<string>, bool> readfile(string filename)
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
    else
    {
        return make_pair(invec, false);
    }
    inp.close();
    return make_pair(invec, true);
}
//Entry point
int main(int argc, char *argv[])
{
    stringstream cmd;
    map<string, Node *> words;
    auto readFileResult = readfile(argv[1]);
    bool isValidFileName = readFileResult.second;
    //Make sure we have the cli arguments!
    if (argc > 1)
    {
        getO
        bool isInteractive = true;
        bool isVerbose = true;
        if (argc > 3)
        {
            string argv_2(argv[2]);
            string argv_3(argv[3]);
            if (argv_2 == "-ni" || argv_2 == "-non-interactive")
            {
                cout << "Non-interactive mode engagdged" << endl;
                bool isInteractive = false;

                if (argv_3 == "-nv" || argv_3 == "-non-verbose")
                {
                    cout << "Non-verbose mode engadged" << endl;
                    bool isVerbose = false;
                }
            }
        }
        else
        {
            cout << "More args please" << endl;
        }

        /*  if (isValidFileName)
        {
            bool is_case_sensitive = true;
            int i = 1;
            for (string s : readFileResult.first)
            {

                storm_lib::rtrim(s);

                Node *n = new Node();
                n->is_majorCase = isupper(s[0]);
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
            while (!cin.eof())
            {

                cout << "Enter a word(" << ((is_case_sensitive) ? "case-sensitive): " : "not case-sensitive): ");
                getline(cin, instr);
                if (instr.empty() && !cin.eof())
                {
                    cerr << "You must enter a word!" << endl;
                    continue;
                }
                //Make sure that no code is executed if we have an eof
                else if (cin.eof())
                {
                    cout << endl;
                    break;
                }
                //Verify there are no extra spaces at the end or the beginning
                storm_lib::trim(instr);
                //Check if the iterator is not at the end of the words map
                if (words.find(instr) != words.end())
                {
                    auto it = words.find(instr);
                    cout << (string)(*(it->second)) << endl;
                }
                //The given word does not appear in the map
                else
                {

                    cout << "Could not locate: " << instr << endl;
                }
            }
        }
        //File not readable
        else
        {
            cout << "Could not open: " << argv[1] << endl;
        } */
    }
    //File not named
    else
    {
        cout << "Must provide name of input file." << endl;

        return 1;
    }

    return 0;
}
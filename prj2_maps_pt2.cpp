#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <map>
#include "./storm_lib.h"
#include <climits>
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
std::string getCmdOutput(const std::string &mStr)
{
    std::string result, file;
    FILE *pipe{popen(mStr.c_str(), "r")};
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    {
        file = buffer;
        result += file.substr(0, file.size() - 1);
    }

    pclose(pipe);
    return result;
};
int main(int argc, char *argv[])
{
    stringstream cmd;
    map<string, Node *> words;
    if (argc > 1)
    {
        bool is_case_sensitive = true;
        int i = 1;
        for (string s : readfile(argv[1]))
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
        while (instr != "quit")
        {

            cout << "Enter a word(" << ((is_case_sensitive) ? "case-sensitive): " : "not case-sensitive): ");
            getline(cin, instr);
            if (instr.empty())
            {
                cerr << "You must enter a word!" << endl;
                continue;
            }
            storm_lib::trim(instr);
            if (!isalpha(instr[0]) && !isdigit(instr[0]))
            {
                break;
            }
            //cout << instr << endl;
            if (!is_case_sensitive)
            {
                int i = 0;
                for (char c : instr)
                {
                    instr[i] = tolower(c);
                    i++;
                }
            }

            if (words.find(instr) != words.end())
            {
                auto it = words.find(instr);
                cout << (string)(*(it->second)) << endl;
                cout << "would you like to open the first occurrence in vscode? (No): ";

                string option;
                getline(std::cin, option);
                if (storm_lib::trim(option) == "no" || option.empty())
                {
                    cout << "will not open file. Continuing with program..." << endl;
                }

                else if (!option.empty() || option == "yes")
                {
                    cout << "opening " << argv[1] << " at line " << it->second->appears_on_lines[0] << endl;
                    cmd << R"(code-insiders --goto )"
                        << argv[1]
                        << ":" << it->second->appears_on_lines[0] << ":1";
                    getCmdOutput(cmd.str());
                    cmd.str(std::string());
                }
            }
            else
            {
                cout << "Could not locate: " << instr << endl;
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
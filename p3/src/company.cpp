#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/function_lib.h"
#include "../include/company.h"

using namespace std;
bool company::get_companies(std::map<std::string, company> &c_map, const char *filename)
{
    stringstream ss;
    string line;

    ifstream inp(filename);
    if (inp.is_open())
    {
        int i = 0;
        while (getline(inp, line))
        {
            vector<string> tokens;
            function_lib::Split(tokens, line, ",");
            if (tokens.size() != 6)
            {
                //cout << "we are false!" << endl;
                return false;
            }
            c_map.emplace(tokens[0], company(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]));
            i++;
        }
        return true;
    }
    return false;
}
#include "split.hpp"

using namespace std;

/*	Split a line containing comma separated values into the
	distinct tokens (values).

	Given a line to split and a delimiter to use (typicallt a
	comma), return a vector of strings (each value from the CSV).
*/

void Split(vector<string> &tokens, string &line, string &delimeter)
{
    tokens.clear();
    size_t pos;
    while ((pos = line.find(delimeter)) != string::npos)
    {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + delimeter.length());
    }
    if (line.length() > 0)
    {
        tokens.push_back(line);
    }
}
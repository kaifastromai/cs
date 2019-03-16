#include "function_lib.h"
#include <string>
#include <vector>
/*	Split a line containing comma separated values into the
	distinct tokens (values).

	Given a line to split and a delimiter to use (typicallt a
	comma), return a vector of strings (each value from the CSV).
*/

void function_lib::Split(std::vector<std::string> &tokens, std::string &line, std::string delimeter)
{
    tokens.clear();
    size_t pos;
    while ((pos = line.find(delimeter)) != std::string::npos)
    {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + delimeter.length());
    }
    if (line.length() > 0)
    {
        tokens.push_back(line);
    }
};

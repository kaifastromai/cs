#pragma once
#include <map>
#include <vector>
#include <string>

class function_lib
{
public:
  //Split a string via a delimeter and push_back the substrings intro a string vector array (by reference)
  static void Split(std::vector<std::string> &tokens, std::string &line, std::string delimeter);

  //Cast a float to a string safely
  static bool SafeFloatFromString(std::string &input, float &v)
  {
    bool retval = true;
    v = 0;
    try
    {
      v = std::stof(input);
    }
    catch (const std::invalid_argument &)
    {
      retval = false;
    }
    return retval;
  }
};
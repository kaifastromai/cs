#pragma once
#include <map>
#include <vector>
#include <string>

class function_lib
{
public:
  static void Split(std::vector<std::string> &tokens, std::string &line, std::string delimeter);
  static void map_from_csv(std::map<std::string, int32_t> &m);
  static void map_from_csv(std::map<int32_t, std::string> &m);
  static void multimap_from_csv();

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
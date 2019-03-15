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
};
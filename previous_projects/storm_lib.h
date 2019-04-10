#pragma once
#include <string>
#include <cctype>
#include <algorithm>
#include <map>
class storm_lib
{
  public:
    static inline void ltrim(std::string &s)
    {
        std::map<int, int> in;
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                    return !std::isspace(ch);
                }));
    };

    // trim from end (in place)
    static inline void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                    return !std::isspace(ch);
                })
                    .base(),
                s.end());
    };

    // trim from both ends (in place)
    static inline std::string trim(std::string &s)
    {
        std::string ins;
        ltrim(s);
        rtrim(s);
        ins = s;
        return ins;
    };
};
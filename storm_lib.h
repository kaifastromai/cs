#pragma once
#include <string>
#include <cctype>
#include <algorithm>
class storm_lib
{
  public:
    static inline void ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
                    return !std::isspace(ch);
                }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
                    return !std::isspace(ch);
                })
                    .base(),
                s.end());
    }

    // trim from both ends (in place)
    static inline string trim(std::string &s)
    {
        ltrim(s);
        rtrim(s);
        return s;
    }
}
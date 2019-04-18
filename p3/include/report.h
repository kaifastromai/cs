#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

class report
{
  public:
    report();
    std::string id, name, state;
    float total;
    int purchases = 2;
    report(std::string id, std::string name, std::string state, int purchases, float total)
    {
        this->id = id;
        this->name = name;
        this->state = state;
        this->purchases = purchases;
        this->total = total;
    };
    operator std::string()
    {
        std::stringstream ss;
        ss.imbue(std::locale::global(std::locale("")));
        ss << std::fixed << std::setprecision(2);
        ss.width(10);
        ss << std::left << id;
        ss.width(40);
        ss << name;
        ss.width(12);
        ss << state;
        ss.width(15);
        ss << purchases;
        ss << "$" << total;
        return ss.str();
    }
};
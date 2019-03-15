#pragma once
#include <string>
#include <map>

class company
{
public:
  company();
  company(std::string id, std::string name, std::string address, std::string state, std::string city, std::string zip)
  {
    this->id = id;
    this->name = name;
    this->state = state;
    this->address = address;
    this->city = city;
    this->zip = zip;
  };
  static bool get_companies(std::map<std::string, company> &c_map, const char *filename);
  std::string id,
      name, state, address, city, zip;
  operator std::string()
  {
    return name + ", " + state + ", " + address + ", " + city + ", " + zip;
  }
};

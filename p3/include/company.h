#pragma once
#include <string>
#include <map>

class company
{
public:
  //Defualt constructer
  company();
  //Instantiate the company class with specified values
  company(std::string id, std::string name, std::string address, std::string city, std::string state, std::string zip)
  {
    this->id = id;
    this->name = name;
    this->state = state;
    this->address = address;
    this->city = city;
    this->zip = zip;
  };
  //Create a map of companies based upon a csv file ordered by their id number
  static bool get_companies(std::map<std::string, company> &c_map, const char *filename);
  std::string id,
      name, state, address, city, zip;
  float total_spent = 0.0;
  int purchases = 0;
  operator std::string()
  {
    return id + ", " + name + ", " + state + ", " + address + ", " + city + ", " + zip;
  }
};

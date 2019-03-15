//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include "company.h"

using namespace std;

int main(int argc, char *argv[])
{
    while (argc == 2)
    {
        cout.imbue(std::locale(""));
        map<int32_t, string> idToDetails;
        map<string, company> idToCompany;
        company::get_companies(idToCompany, argv[1]);
        cout << (string)idToCompany.at("00000000") << endl;
    }
}
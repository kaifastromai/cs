//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include "company.h"
#include "purchase.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        cout.imbue(std::locale(""));
        multimap<string, company> idToTransactions;
        map<string, company> idToCompany;
        map<string, string> nameToId;
        company::get_companies(idToCompany, argv[1]);
        purchase::get_purchases(idToTransactions, argv[2]);
        cout << (string)(idToTransactions.find("00000000"))->second << endl;
    }
}
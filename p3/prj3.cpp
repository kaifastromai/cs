//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <stdio.h>
#include "company.h"
#include "purchase.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        cout.imbue(std::locale(""));
        multimap<string, purchase> idToTransactions;
        map<string, company> idToCompany;
        map<string, string> nameToId;
        company::get_companies(idToCompany, argv[1]);
        purchase::get_purchases(idToTransactions, argv[2]);
        purchase::get_total_purchases(idToCompany.at("00000000"), idToTransactions);
        cout << to_string(idToCompany.at("00000000").total_purchases) << endl;
    }
}
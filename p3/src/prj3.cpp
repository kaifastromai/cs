//
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <locale>
#include "../include/company.h"
#include "../include/purchase.h"
#include "../include/report.h"

using namespace std;

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        //Set locale to system for std::cout (properly formatting numbers...etc)
        cout.imbue(std::locale(""));
        multimap<string, purchase> idToTransactions;
        map<string, company> idToCompany;
        map<string, string> nameToId;
        //create vector to hold the reports
        vector<report> reports;
        //make sure the company.csv file is properly formatted before we continue!
        if (!company::get_companies(idToCompany, argv[1]))
        {
            cout << "This is not a valid company file! Maybe you switched the order? (company.csv data.csv)" << endl;
            return 1;
        };
        //same with the data.csv
        if (!purchase::get_purchases(idToTransactions, argv[2]))
        {
            cout << "This is not a valid data file! Maybe you switched the order? (company.csv data.csv)" << endl;
            return 1;
        }

        cout << "File: " << argv[1] << " contained " << idToCompany.size() << " records." << endl;
        cout << "File: " << argv[2] << " contained " << idToTransactions.size() << " records." << endl;
        cout << "Sales summary report:" << endl;
        cout << "=====================" << endl;

        for (auto it = idToCompany.begin(); it != idToCompany.end(); it++)
        {
            purchase::get_total_purchases(it->second, idToTransactions);
            nameToId.emplace((it->second).name, (it->second).id);
        }
        //Create reports for each company instead of just printing. We store them in case we need them later
        for (auto it2 = nameToId.begin(); it2 != nameToId.end(); it2++)
        {
            auto company = idToCompany.at(it2->second);
            reports.push_back(report(company.id,
                                     company.name,
                                     company.state,
                                     company.purchases,
                                     company.total_spent));
        }
        cout << std::fixed << std::setprecision(2);
        cout.width(10);
        cout << left << "ID:";
        cout.width(40);
        cout << "Name:";
        cout.width(12);
        cout << "State:";
        cout.width(15);
        cout << "Purchases:";
        cout.width(15);
        cout << "Total:" << endl;
        for (auto rp : reports)
        {
            cout << (string)rp << endl;
        }
    }
    //Check for errors relating to the command line
    else if (argc == 1)
    {
        cout << "You must give the company and data files!" << endl;
        return 1;
    }
    else if (argc == 2)
    {
        cout << "You must specify the data file!" << endl;
        return 1;
    }
    else
    {
        cout << "An unexpected error relating to command line arguments occured!" << endl;
        return 1;
    }
}
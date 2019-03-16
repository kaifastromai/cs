
#include <iostream>
#include <fstream>
#include "purchase.h"
#include "function_lib.h"
using namespace std;
void purchase::get_total_purchases(company &c, std::multimap<std::string, purchase> &idToPurchase)
{
	auto ret = idToPurchase.equal_range(c.id);
	for (auto it = ret.first; it != ret.second; it++)
	{
		c.total_purchases += it->second.amount;
	}
}
bool get_purchases(std::multimap<std::string, purchase> &idToPurchase, const char *dataFile)
{
	ifstream inp(dataFile);
	if (inp.is_open())
	{
		string line;
		while (getline(inp, line))
		{
			float amount;

			vector<string> tokens;
			function_lib::Split(tokens, line, ",");
			function_lib::SafeFloatFromString(tokens[3], amount);
			idToPurchase.emplace(tokens[0], purchase(tokens[0], tokens[1], tokens[2], amount));
		}
	}
	return false;
}

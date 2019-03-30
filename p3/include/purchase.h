#pragma once
#include <string>
#include <map>
#include "company.h"

class purchase
{
public:
  purchase();
  purchase(std::string company_id, std::string invoice, std::string transaction_date, float amount)
  {
    this->company_id = company_id;
    this->invoice = invoice;
    this->transaction_date = transaction_date;
    this->amount = amount;
  }
  std::string company_id, invoice, transaction_date;
  float amount;
  //Enumerate through all of the company purchases(via id) and add them together and set their(the companies) total_amount variables (by reference)
  static void get_total_purchases(company &c, std::multimap<std::string, purchase> &idToPurchase);
  static bool get_purchases(std::multimap<std::string, purchase> &idToPurchase, const char *dataFile);

  //overload the string method, for testing purposes
  operator std::string()
  {
    return company_id + ", " + invoice + ", " + transaction_date + ", " + std::to_string(amount);
    ;
  }
};
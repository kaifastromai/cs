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

  static void get_total_purchases(company &c, std::multimap<std::string, purchase> &idToPurchase);
  static bool get_purchases(std::multimap<std::string, purchase> &idToPurchase, const char *dataFile);

  operator std::string()
  {
    return company_id + ", " + invoice + ", " + transaction_date + ", " + std::to_string(amount);
    ;
  }
};
#include <string>
#include <map>

class purchase
{
  public:
    purchase();
    purchase(std::string company_id, std::string invoice, int32_t amount, std::string transaction_date)
    {
        this->company_id = company_id;
        this->invoice = invoice;
        this->transaction_date = transaction_date;
    }
    std::string company_id, invoice, transaction_date;
}
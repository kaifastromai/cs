#include <iostream>
using namespace std;

class CarCounter
{
  public:
    CarCounter();
    CarCounter(const CarCounter &origCarCounter);
    void SetCarCount(const int count)
    {
        carCount = count;
    }
    int GetCarCount() const
    {
        return carCount;
    }

  private:
    int carCount;
};
CarCounter::CarCounter(const CarCounter &origCarCounter)
{
    SetCarCount(origCarCounter.carCount);
}

CarCounter::CarCounter()
{
    carCount = 0;
}

void CountPrinter(CarCounter carCntr)
{
    cout << "Cars counted: " << carCntr.GetCarCount();
}

int main()
{
    CarCounter parkingLot;
    parkingLot.SetCarCount(5);
    CountPrinter(parkingLot);

    return 0;
}